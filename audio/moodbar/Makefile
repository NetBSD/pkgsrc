# $NetBSD: Makefile,v 1.10 2019/10/18 17:14:34 nia Exp $

DISTNAME=	moodbar-1.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=exaile/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/exaile/moodbar
COMMENT=	Audio timeline visualization
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++14

# C++14
GCC_REQD+=	5

.include "../../devel/meson/build.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
