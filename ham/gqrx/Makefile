# $NetBSD: Makefile,v 1.1 2025/02/24 11:56:42 jmcneill Exp $

DISTNAME=	gqrx-2.17.6
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=gqrx-sdr/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gqrx-sdr/gqrx/
COMMENT=	open source software defined radio receiver
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../ham/gnuradio-digital/buildlink3.mk"
.include "../../ham/gnuradio-network/buildlink3.mk"
.include "../../ham/gr-osmosdr/buildlink3.mk"
.include "../../math/volk/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
