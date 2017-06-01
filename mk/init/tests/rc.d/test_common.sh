# $NetBSD: test_common.sh,v 1.1 2017/06/01 02:08:05 jlam Exp $
#
# Copyright (c) 2017 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Johnny C. Lam.
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

common_setup()
{
	: ${CAT:=cat}
	: ${ECHO:=echo}
	: ${MKDIR:=mkdir}

	${MKDIR} work
	${CAT} > work/Makefile << 'EOF'
.include "${PKGSRCDIR}/mk/init/tests/rc.d/test.mk"

# Define the package-settable RCD_SCRIPTS variable.
RCD_SCRIPTS=	daemond

.include "${PKGSRCDIR}/mk/init/bsd.init.mk"
EOF

	${CAT} > work/daemond_body << 'EOF'
. /etc/rc.subr

name="daemond"
rcvar=$name
command="/usr/pkg/sbin/daemond"
load_rc_config $name
run_rc_command "$1"
EOF
	# Example rc.d script.
	( ${ECHO} "#!@RCD_SCRIPTS_SHELL@"
	  ${CAT} work/daemond_body ) > work/daemond.sh
	# Expected rc.d script.
	( ${ECHO} "#!/bin/sh"
	  ${CAT} work/daemond_body ) > work/daemond
}

common_teardown()
{
	: ${RM:=rm}

	${RM} -fr work
}
