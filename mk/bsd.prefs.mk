# $NetBSD: bsd.prefs.mk,v 1.3 1998/08/19 16:23:40 tv Exp $
#
# Make file, included to get the site preferences, if any.  Should
# only be included by package Makefiles before any .if defined()
# statements, to make sure any variables defined in /etc/mk.conf or
# $MAKECONF are used.

.if !defined(OPSYS)
OPSYS!= /usr/bin/uname -s
.endif

# Don't complain about environment settings on recursive makes.
__PREFIX_SET__=${PREFIX}

.if defined(MAKECONF) && exists(${MAKECONF})
.include "${MAKECONF}"
.elif ${OPSYS} == "FreeBSD" && exists(/etc/make.conf)
.include "/etc/make.conf"
.elif exists(/etc/mk.conf)
.include "/etc/mk.conf"
.endif

.if defined(PREFIX) && (${PREFIX} != ${__PREFIX_SET__})
.BEGIN:
	@${ECHO_MSG} "You can NOT set PREFIX manually or in mk.conf.  Set LOCALBASE or X11BASE"
	@${ECHO_MSG} "depending on your needs.  See the pkg system documentation for more info."
	@${FALSE}
.endif
