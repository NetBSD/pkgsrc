# $NetBSD: Makefile,v 1.12 2004/01/22 07:15:01 grant Exp $
#

DISTNAME=	neato
PKGNAME=	xmms-neato-20010818
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.rpi.edu/~mullr/xmms/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.rpi.edu/~mullr/xmms/
COMMENT=	Circle effect XMMS plugin

USE_BUILDLINK2=	yes
USE_X11=	yes
USE_GNU_TOOLS+=	make
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
