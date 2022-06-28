# $NetBSD: Makefile,v 1.4 2022/06/28 11:36:12 wiz Exp $

DISTNAME=	libxml++-5.0.1
PKGNAME=	${DISTNAME:S/libxml++/libxml++5.0/}
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxml++/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	http://libxmlplusplus.sourceforge.net/
COMMENT=	C++ wrapper for the libxml XML parser library (5.0 API)
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config perl
# TODO: update
PKGCONFIG_OVERRIDE+=	libxml++-2.6.pc.in
PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../devel/glibmm2.68/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
