# $NetBSD: Makefile,v 1.8 2015/04/25 14:20:30 tnn Exp $

DISTNAME=	gbase-0.5
PKGREVISION=	7
CATEGORIES=	converters math
MASTER_SITES=	http://www.fluxcode.net/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://fluxcode.net/projects/gbase-2
COMMENT=	GTK program designed to convert between the four common bases
LICENSE=	artistic

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	bin

BUILD_TARGET=	gbase

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/gbase ${DESTDIR}${PREFIX}/bin/gbase

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
