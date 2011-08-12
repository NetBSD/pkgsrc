#!/usr/pkg/bin/ruby
# -*- coding: utf-8 -*-
#
# $NetBSD: update-gemspec.rb,v 1.1 2011/08/12 14:35:34 taca Exp $
#
# Copyright (c) 2011 The NetBSD Foundation, Inc.
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
require 'yaml'
require 'fileutils'
require 'optparse'

class Gem::Specification
  def get_dependencies
    return @dependencies
  end
end

class Gem::Requirement
  def get_requirement
    return @requirement
  end
end

class GemSpecUpdater
  OrigSuffix = '.orig_gemspec'

  def initialize(file)
    @file = file
    open(file) { |f|
      @spec = Gem::Specification.from_yaml(f)
    }
    @requirements = {}
  end

  #
  # rule should be:
  #	rule ::= name_spec op version
  #	name_sec ::= name [ : new_name ]
  #
  def parse_rules(rules)
    rules.each do |s|
      s.split.each do |dep|
        names = op = ver = nil
        if /([a-z0-9_:-]+)([=!><\~][=>]*)(.*)/ =~ dep
          names = $1
          op = $2
          ver = $3
        end
        r = Gem::Version.new ver
        name, new_name = names.split(/:/, 2)
        @requirements[name] = { :op => op, :version => r, :name => new_name }
      end
    end
  end

  def modify
    dependencies = @spec.runtime_dependencies

    dependencies.each do |dep|
      name = dep.name
      update = @requirements[name]
      unless update.nil?
        r = dep.requirement.requirements
        r[0][0] = update[:op]
        r[0][1] = update[:version]
        unless update[:name].nil?
          dep.name = update[:name]
        end
      end
    end
  end

  def update
    FileUtils.cp(@file, @file + OrigSuffix, :preserve => true)
    
    open(@file, "w") { |f|
      f.print YAML.dump(@spec) + "\n"
    }
  end

  def dump_dependency
    dependencies = @spec.runtime_dependencies

    dependencies.each do |dep|
      puts "#{dep.name} #{dep.requirement}"
    end
  end
end

def usage
  $stderr.puts <<"EOF"
#{$0}: [-n] [-o] [-h] gemspec [rules ...]
	Update gemspec with as version patterns.
	Options:
	-h	Show this help.
	-n	Don't update gemspec file.
	-o	Don't update gemspec file and show original dependency.

EOF
  exit
end

ENV['TZ'] = 'UTC'

show = false
update = true

opt = OptionParser.new
opt.on('-n') { show = true }
opt.on('-o') { show = true; update = false }
opt.on('-h') { usage }

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
