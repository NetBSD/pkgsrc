# $NetBSD: Makefile,v 1.9 2003/05/02 11:53:53 wiz Exp $
#

DISTNAME=	neato
PKGNAME=	xmms-neato-20010818
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.rpi.edu/~mullr/xmms/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.rpi.edu/~mullr/xmms/
COMMENT=	Circle effect XMMS plugin

USE_BUILDLINK2=	yes
USE_X11=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig

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

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
