# $NetBSD: Makefile,v 1.16 2018/11/14 22:21:11 kleink Exp $

DISTNAME=	gbase-0.5
PKGREVISION=	14
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
