# $NetBSD: Makefile,v 1.19 2006/02/05 23:08:18 joerg Exp $
#

DISTNAME=	neato
PKGNAME=	xmms-neato-20010818
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://www.rpi.edu/~mullr/xmms/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.rpi.edu/~mullr/xmms/
COMMENT=	Circle effect XMMS plugin

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

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
