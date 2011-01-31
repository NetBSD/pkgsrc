# $NetBSD: image.rb,v 1.1.1.1 2011/01/31 20:56:14 jym Exp $
#
# Copyright (c) 2011 Jean-Yves Migeon <jym@NetBSD.org>
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
#------------------------------------------------------------------------------

require 'fileutils'
require 'ec2/platform/netbsd/mtab'
require 'ec2/platform/netbsd/fstab'
require 'ec2/platform/netbsd/constants'

module EC2
  module Platform
    module NetBSD

      # Implements all the required commands to generate a NetBSD image
      # file. Note that the tools used here are specific to NetBSD; so
      # you have to use a NetBSD environment to create the file, or build
      # the tools from a NetBSD src tree (./build.sh -T TOOLDIR tools) and
      # add TOOLDIR to PATH.
      class Image

        EXCLUDES = ['/kern', '/proc']
        
        def initialize(volume, img_filename, img_size, exclude_dirs,
                       fstab = nil, debug = false)

          @volume = volume
          @img_filename = img_filename
          @img_size = img_size # in MiB
          @exclude_dirs = exclude_dirs
          @debug = debug
          @fstab = (fstab.nil? ? EC2::Platform::NetBSD::Fstab::DEFAULT : fstab)

        end

        # Make the image file.
        # Just use the tree generated via a ./build.sh release &&
        # ./build.sh install=/path/to/volume run from a NetBSD src tree.
        # build.sh nearly takes care of everything, but for more advanced
        # customization, the user should edit the files directly within
        # the generated tree.
        def make
          puts "Generating image file #{@img_filename} from path #{@volume}"

          if not @exclude_dirs.nil?
            puts "WARNING: Excluding directories operation is not supported."
            puts "The following directories will NOT be excluded from " \
              "image file:"
            @exclude_dirs.each { |dir| puts("#{dir}\t") }
          end

          ### TODO Update fstab, etc... (do the extreme
	  ### minimum here, the script should not alter the install tree too
	  ### heavily)
         
          execute("makefs -s '#{@img_size}m' -B le -o density=32k " \
            "'#{@img_filename}' '#{@volume}'")

          puts "Image #{@img_filename} successfully created."
        end

        def execute(cmd)
          if @debug
            puts "Executing command: '#{cmd}'"
          end

          raise FatalError.new("Command '#{cmd}' failed") unless system(cmd)
        end
 
      end

    end
  end
end
