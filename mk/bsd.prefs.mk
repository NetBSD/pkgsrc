# $NetBSD: bsd.prefs.mk,v 1.4 1998/11/26 23:39:15 hubertf Exp $
#
# Make file, included to get the site preferences, if any.  Should
# only be included by package Makefiles before any .if defined()
# statements, to make sure any variables defined in /etc/mk.conf or
# $MAKECONF are used.

# Let people know this is bsd.pkg.mk, so they can set up their
# /etc/mk.conf accordingly  
BSD_PKG_MK=1 

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
