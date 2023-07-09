# $NetBSD: Makefile,v 1.12 2023/07/09 14:24:08 nia Exp $

DISTNAME=	libsigc++-3.2.0
PKGNAME=	${DISTNAME:S/-/3-/}
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsigc++/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libsigcplusplus/libsigcplusplus
COMMENT=	Type-safe callback system for C++ programs
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_TOOLS+=		gm4 pkg-config
PKGCONFIG_OVERRIDE=	sigc++.pc.in

# C++17
GCC_REQD+=		7

.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.mm-common+=	mm-common>=0.9.10
.include "../../devel/mm-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
