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
	${MKDIR} work/smf
	${CAT} > work/Makefile << 'EOF'
# Define PKGBASE used as default for ${SMF_NAME}.
PKGBASE=	smf-test

.include "${PKGSRCDIR}/mk/init/tests/smf/test.mk"

SMF_METHODS=	daemond

.include "${PKGSRCDIR}/mk/init/bsd.init.mk"
EOF
	# Example SMF manifest
	${CAT} > work/smf/manifest.xml << 'EOF'
<?xml version='1.0'>
<!DOCTYPE service_bundle SYSTEM '/usr/share/lib/xml/dtd/service_bundle.dtd.1'>
<service_bundle type='manifest' name='export'>
  <service name='@SMF_PREFIX@/@SMF_NAME@' type='service' version='1'>
    <exec_method name='start' type='method' exec='@PREFIX@/@SMF_METHOD_FILE.daemond@ start' timeout_seconds='60'/>
    <exec_method name='stop' type='method' exec=':kill' timeout_seconds='60'/>
    <template>
      <documentation>
        <manpage title='daemond' section='1M' manpath='@PREFIX@/@PKGMANDIR@'/>
      </documentation>
    </template>
  </service>
</service_bundle>
EOF
	# Expected SMF manifest
	${CAT} > work/manifest.xml << 'EOF'
<?xml version='1.0'>
<!DOCTYPE service_bundle SYSTEM '/usr/share/lib/xml/dtd/service_bundle.dtd.1'>
<service_bundle type='manifest' name='export'>
  <service name='pkgsrc/smf-test' type='service' version='1'>
    <exec_method name='start' type='method' exec='/usr/pkg/lib/svc/method/daemond start' timeout_seconds='60'/>
    <exec_method name='stop' type='method' exec=':kill' timeout_seconds='60'/>
    <template>
      <documentation>
        <manpage title='daemond' section='1M' manpath='/usr/pkg/share/man'/>
      </documentation>
    </template>
  </service>
</service_bundle>
EOF
	# Example SMF method.
	${CAT} > work/smf/daemond.sh << 'EOF'
#!@SMF_METHOD_SHELL@
PIDFILE=	@VARBASE@/run/daemond.pid
case $1 in
start)		@PREFIX@/sbin/daemond ;;
restart)	[ ! -f "$PIDFILE" ] || kill -HUP `cat "$PIDFILE"` ;;
esac
EOF
	# Expected SMF method.
	${CAT} > work/daemond << 'EOF'
#!/sbin/sh
PIDFILE=	/var/run/daemond.pid
case $1 in
start)		/usr/pkg/sbin/daemond ;;
restart)	[ ! -f "$PIDFILE" ] || kill -HUP `cat "$PIDFILE"` ;;
esac
EOF
}

common_teardown()
{
	: ${RM:=rm}

	${RM} -fr work
}
