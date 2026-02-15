# $NetBSD: Makefile,v 1.1 2026/02/15 16:18:45 wiz Exp $

DISTNAME=	uxplay-1.73.3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=FDH2/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bcallah@posteo.net
HOMEPAGE=	https://github.com/FDH2/UxPlay/
COMMENT=	AirPlay Unix mirroring server
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/UxPlay-${PKGVERSION_NOREV}

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++11

USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DNO_MARCH_NATIVE=ON

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
DEPENDS+=	gst-plugins1-osxaudio-[0-9]*:../../audio/gst-plugins1-osxaudio
DEPENDS+=	gst-plugins1-osxvideo-[0-9]*:../../multimedia/gst-plugins1-osxvideo
.endif

.if ${OPSYS} != "Darwin"
DEPENDS+=	avahi-[0-9]*:../../net/avahi
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.endif
.include "../../devel/cmake/build.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libplist/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
