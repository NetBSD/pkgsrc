# $NetBSD: constants.rb,v 1.1.1.1 2011/01/31 20:56:14 jym Exp $
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

# NetBSD overrides for EC2 AMI tools

require 'ec2/platform/base/constants'

module EC2
  module Platform
    module NetBSD
      module Constants

        module Bundling
          include EC2::Platform::Base::Constants::Bundling

          # Set EC2_HOME environment variable -- value is controlled
          # by pkgsrc's Makefiles of the EC2 API tools package
          EC2_HOME = '@EC2_HOME@'
          EC2_X509_CERT = File.join(EC2_HOME.to_s, '/etc/ec2/amitools/cert-ec2.pem')
          EC2_MAPPING_FILE = File.join(EC2_HOME.to_s, '/etc/ec2/amitools/mappings.csv')
        end

        module Utility
          include EC2::Platform::Base::Constants::Utility

          TAR = 'gtar'
        end

      end
    end
  end
end

