# $NetBSD: Makefile,v 1.18 2019/11/03 17:14:24 rillig Exp $

DISTNAME=	gbase-0.5
PKGREVISION=	15
CATEGORIES=	converters math
MASTER_SITES=	http://www.fluxcode.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
