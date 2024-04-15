# $NetBSD: Makefile,v 1.14 2024/04/15 09:25:06 adam Exp $

DISTNAME=	libsigc++-3.6.0
PKGNAME=	${DISTNAME:S/-/3-/}
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsigc++/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libsigcplusplus/libsigcplusplus
COMMENT=	Type-safe callback system for C++ programs
LICENSE=	gnu-lgpl-v2.1

USE_CXX_FEATURES+=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		gm4 pkg-config
PKGCONFIG_OVERRIDE=	sigc++.pc.in

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/sigc++
# for Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/sigc++

.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.mm-common+=	mm-common>=0.9.10
.include "../../devel/mm-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
