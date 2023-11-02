# $NetBSD: Makefile,v 1.2 2023/11/02 22:13:45 gdt Exp $

DISTNAME=	kalibrate-rtl-20131215
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=steve-m/}
GITHUB_TAG=	aae11c8a8dc79692a94ccfee39ba01e8c8c05d38

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/steve-m/kalibrate-rtl/
COMMENT=	LO frequency offset calibration tool (rtl-sdr fork)
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf automake autoreconf pkg-config

INSTALLATION_DIRS=	bin

pre-configure:
	cd ${WRKSRC} && autoreconf -if

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/kal ${DESTDIR}${PREFIX}/bin/kal-rtl

.include "../../devel/libusb1/buildlink3.mk"
.include "../../ham/rtl-sdr/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
