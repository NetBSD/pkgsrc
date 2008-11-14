# $NetBSD: hacks.mk,v 1.1 2008/11/14 14:09:20 tron Exp $

.if !defined(SENDMAIL_HACKS_MK)
SENDMAIL_HACKS_MK=	# defined

### Work around build problems under NetBSD 5.0_BETA and newer because
### of redefinition of the "boolean" type. See PR pkg/38983 for details.
.  include "../../mk/bsd.fast.prefs.mk"
.  if ${OPSYS} == "NetBSD" && exists(/usr/bin/c99)
PKG_HACKS+=	c99

post-configure:
	${CHMOD} +w ${WRKSRC}/devtools/OS/NetBSD
	${ECHO} "define(\`confCC', \`c99')" >>${WRKSRC}/devtools/OS/NetBSD
.  endif
.endif
