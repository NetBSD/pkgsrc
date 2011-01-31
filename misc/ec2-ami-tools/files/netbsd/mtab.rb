# $NetBSD: mtab.rb,v 1.1.1.1 2011/01/31 20:56:14 jym Exp $
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

module EC2
  module Platform
    module NetBSD

      # Under NetBSD, local file-systems are indicated with a "local"
      # mount option.
      # Sadly, tools are written in such a way that we cannot use this
      # information directly without using ugly hacks. So we rely on a list
      # of file-systems that could only be locally mounted.
      LOCAL_FS_TYPES = ['cd9660', 'ext2fs', 'ffs', 'kernfs', 'lfs',
        'mfs', 'msdos', 'ntfs', 'null', 'procfs', 'tmpfs', 'udf']

      class Mtab

        attr_reader :entries

        def initialize()
          @entries = Hash.new

          `mount`.each_line {|line|
            entry = Entry.new(line)
            @entries[entry.mpoint] = entry
          }
        end

        # NetBSD does not use mnttab to track mounts. Parse this info
        # from mount(8) output instead.
        def self.load
          return self.new()
        end

        class Entry

          attr_reader :device, :mpoint, :fstype, :options, :value

          # Format is <dev> on <mount point> type <fstype> (<options>)
          REGEXP = /^(\S+) on (.+) type (\S+) \(([^)]+)\)$/

          def initialize(value)
            @value = value.strip  # complete line

            if (m = REGEXP.match(@value))
              caps = m.captures
              @device  = caps[0] # device mounted
              @mpoint  = caps[1] # mount point
              @fstype  = caps[2] # fs type
              @options = caps[3] # mount options (comma separated)
            end
          end

        end
      end
    end
  end
end
