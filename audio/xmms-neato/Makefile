# $NetBSD: Makefile,v 1.5 2001/11/29 13:46:10 wiz Exp $
#

DISTNAME=	neato
PKGNAME=	xmms-neato-20010818
CATEGORIES=	audio
MASTER_SITES=	http://www.rpi.edu/~mullr/xmms/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.rpi.edu/~mullr/xmms/
COMMENT=	Circle effect XMMS plugin

GNU_CONFIGURE=	yes
USE_BUILDLINK_ONLY=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig
CPPFLAGS+=	-D_POSIX_THREAD_SYSCALL_SOFT=1

GNU_CONFIGURE=	YES

post-extract:
		cd ${WRKSRC} ; \
		${RM} mkinstalldirs ; \
		${ECHO} "#!/bin/sh" >>mkinstalldirs ; \
		${ECHO} 'exec ${MKDIR} "$$@"' >>mkinstalldirs ; \
		${CHMOD} +x mkinstalldirs ; \
		${RM} install-sh ; \
		${ECHO} "#!/bin/sh" >>install-sh ; \
		${ECHO} 'exec ${INSTALL} "$$@"' >>install-sh ; \
		${CHMOD} +x install-sh ; \
		${MAKE} distclean

.include "../../audio/xmms/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
