# $NetBSD: Makefile,v 1.7 2004/10/03 00:18:15 tv Exp $
#

DISTNAME=	idesk-0.3.5
PKGREVISION=	2
CATEGORIES=	sysutils x11
MASTER_SITES=	http://idesk.sourceforge.net/releases/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://sourceforge.net/projects/idesk/
COMMENT=	Gives users of minimal WMs icons on their desktop

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_X11=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/idesk ${PREFIX}/bin/idesk
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/idesk
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/idesk

.include "../../graphics/imlib/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
