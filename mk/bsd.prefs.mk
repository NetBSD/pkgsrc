# $NetBSD: bsd.prefs.mk,v 1.1 1998/06/03 11:15:29 agc Exp $
#
# Make file, included to get the site preferences, if any.  Should
# only be included by package Makefiles before any .if defined()
# statements, to make sure any variables defined in /etc/mk.conf or
# $MAKECONF are used.

.if !defined(OPSYS)
OPSYS!= /usr/bin/uname -s
.endif

.if defined(MAKECONF) && exists(${MAKECONF})
.include "${MAKECONF}"
.elif ${OPSYS} == "FreeBSD" && exists(/etc/make.conf)
.include "/etc/make.conf"
.elif exists(/etc/mk.conf)
.include "/etc/mk.conf"
.endif

