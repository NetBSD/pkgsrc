# $NetBSD: Makefile,v 1.15 2005/02/21 20:26:09 hubertf Exp $
#

DISTNAME=	neato
PKGNAME=	xmms-neato-20010818
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.rpi.edu/~mullr/xmms/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.rpi.edu/~mullr/xmms/
COMMENT=	Circle effect XMMS plugin

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
USE_X11=	yes

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

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
