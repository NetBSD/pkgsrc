# $NetBSD: Makefile,v 1.1 2019/10/03 14:30:41 nia Exp $

DISTNAME=	gst-transcoder-1.16.0
PKGNAME=	${DISTNAME:S/^gst/gst-plugins1/1}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=pitivi/}
GITHUB_PROJECT=	gst-transcoder

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pitivi/gst-transcoder
COMMENT=	Open source multimedia framework - transcoding plugin
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		py
SUBST_STAGE.py=		pre-configure
SUBST_MESSAGE.py=	Setting the Python executable name.
SUBST_FILES.py+=	meson.build
SUBST_VARS.py+=		PYVERSSUFFIX

.include "../../devel/py-meson/build.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
