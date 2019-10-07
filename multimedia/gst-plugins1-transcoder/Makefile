# $NetBSD: Makefile,v 1.3 2019/10/07 09:28:12 prlw1 Exp $

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

# workaround for build failure
# https://gitlab.gnome.org/GNOME/json-glib/issues/35
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output

MESON_ARGS+=	-Ddisable_doc=true

.include "../../devel/meson/build.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
