# $NetBSD: bsd.prefs.mk,v 1.2 1998/08/11 19:30:48 tv Exp $
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

.if defined(PREFIX)
.BEGIN:
	@${ECHO_MSG} "You can NOT set PREFIX manually or in mk.conf.  Set LOCALBASE or X11BASE"
	@${ECHO_MSG} "depending on your needs.  See the pkg system documentation for more info."
	@${FALSE}
.endif
