#!/usr/pkg/bin/ruby
# -*- coding: utf-8 -*-
#
# $NetBSD: update-gemspec.rb,v 1.7 2014/07/20 01:11:28 obache Exp $
#
# Copyright (c) 2011, 2012, 2013 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Takahiro Kambe.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#

#
# This is a quick and dirty tool which updates gemspec file:
#
require 'rubygems'
require 'fileutils'
require 'optparse'

class GemSpecUpdater
  OrigSuffix = '.orig_gemspec'

  def initialize(file)
    @file = file
    @spec = Gem::Specification.load(@file)
    @requirements = {}
    @attr = {}
  end

  #
  # rule should be:
  #	rule ::= dependecy_specs | attr_specs
  #	dependency_specs ::= dependency_spec [ SPACE dependency_spec ]
  #	dependency_spec ::= name_spec [ dependency ]
  #	name_spec ::= name [ ":" new_name ]
  #	dependency ::= <Rubygem's dependecy operator and version string>
  #	attr_specs ::= ":" attr_name attr_operations
  #	attr_operations ::= assign_operation | array_operation
  #	assign_operation ::= "=" [ new_value ]
  #	array_operations ::= attr_op [ attr_op ]
  #	attr_op ::= new | old=new | old=
  #
  def parse_rules(rules)
    key = nil
    rules.each do |s|
      s.split.each do |ru|
        if key.nil? and /^:([a-z_]+)=(\S+)*/ =~ ru
          key = $1
          var = $2
          @attr[key] = var
          key = nil
        elsif /^:([a-z_]+)+/ =~ ru
          key = $1
          @attr[key] = []
        elsif not key.nil?
          @attr[key].push ru unless key.nil?
        else
          if /([a-z0-9_.:-]+)([=!><\~][=>]*)(.*)/ =~ ru
            names = $1
            op = $2
            ver = $3
            r = Gem::Version.new ver
            name, new_name = names.split(/:/, 2)
            @requirements[name] = {
              :method => :update,
              :op => op,
              :version => r,
              :name => new_name
            }
          elsif /([a-z0-9_-]+):$/ =~ ru
            name = $1
            @requirements[name] = {
              :method => :delete,
            }
          end
        end
      end
    end
  end

  def modify
    dependencies = @spec.instance_variable_get(:@dependencies)
    dependencies.each do |dep|
      next if dep.type != :runtime
      update = @requirements[dep.name]
      if not update.nil? and update[:method] == :update
        r = dep.requirement.requirements
        r[0][0] = update[:op]
        r[0][1] = update[:version]
        unless update[:name].nil?
          dep.name = update[:name]
        end
      end
    end
    dependencies.delete_if { |dep|
      next if dep.type != :runtime
      update = @requirements[dep.name]
      not update.nil? and update[:method] == :delete
    }

    @attr.keys.each do |name|
      modified = false
      av = eval "@spec.#{name}"
      if av.class == String
        nv = @attr[name]
        av = nv
        modified = true
      elsif av.class == Array
        operation = @attr[name]
        operation.each do |op|
          if /^([^=]+)=([^=]+)$/ =~ op
            ov = $1
            nv = $2
            if av.include? ov
              av.delete ov
              modified = true
            end
            unless av.include? nv
              av.push nv
              modified = true
            end
          elsif /^([^=]+)=$/ =~ op
            ov = $1
            if av.include? ov
              av.delete(ov)
              modified = true
            end
          end
        end
      end
      if modified
        eval "@spec.#{name} = av"
      end
    end
  end

  def update
    FileUtils.cp(@file, @file + OrigSuffix, :preserve => true)

    open(@file, "w") { |f|
      f.print @spec.to_ruby
    }
  end

  def dump_dependency
    dependencies = @spec.runtime_dependencies

    dependencies.each do |dep|
      puts "#{dep.name} #{dep.requirement}"
    end
  end
end

def usage(status)
  $stderr.puts <<"EOF"
#{File.basename($0)}: [-n] [-o] [-h] gemspec [rules ...]
	Update gemspec with as version patterns.
	Options:
	-h	Show this help.
	-n	Don't update gemspec file.
	-o	Don't update gemspec file and show original dependency.

EOF
  Process.exit status
end

ENV['TZ'] = 'UTC'

show = false
update = true

opt = OptionParser.new
opt.on('-n') { show = true }
opt.on('-o') { show = true; update = false }
opt.on('-h') { usage 0 }

if ARGV.size < 1
  usage 1
end

opt.parse!(ARGV)

file = ARGV.shift
rules = ARGV

updater = GemSpecUpdater.new file
updater.parse_rules rules
updater.modify if update
if show
  updater.dump_dependency
else
  updater.update
end
