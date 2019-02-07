# $NetBSD: Makefile,v 1.1 2019/02/07 14:03:22 tnn Exp $

DISTNAME=	kalibrate-hackrf-20160704
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=scateu/}
GITHUB_TAG=	2492c20822ca6a49dce97967caf394b1d4b2c43e

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scateu/kalibrate-hackrf/
COMMENT=	LO frequency offset calibration tool (hackrf fork)
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS=	autoconf automake autoreconf pkg-config

INSTALLATION_DIRS=	bin

pre-configure:
	cd ${WRKSRC} && autoreconf -if

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/kal ${DESTDIR}${PREFIX}/bin/kal-hackrf

.include "../../devel/libusb1/buildlink3.mk"
.include "../../ham/hackrf/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
