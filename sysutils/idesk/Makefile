# $NetBSD: Makefile,v 1.3 2004/01/24 15:06:57 grant Exp $
#

DISTNAME=	idesk-0.3.5
PKGREVISION=	1
CATEGORIES=	sysutils x11
MASTER_SITES=	http://idesk.timmfin.net/releases/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://idesk.timmfin.net/
COMMENT=	Gives users of minimal WMs icons on their desktop

USE_BUILDLINK2=	yes
USE_GNU_TOOLS+=	make
USE_X11=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/idesk ${PREFIX}/bin/idesk
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/idesk
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/idesk

.include "../../graphics/imlib/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
