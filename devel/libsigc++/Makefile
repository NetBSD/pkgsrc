# $NetBSD: Makefile,v 1.67 2022/07/25 19:22:22 wiz Exp $

DISTNAME=	libsigc++-2.10.8
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsigc++/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libsigcplusplus/libsigcplusplus
COMMENT=	Type-safe callback system for C++ programs (v2)
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	libsigc++2-[0-9]*
GCC_REQD+=	4.8

USE_LANGUAGES=		c c++11
USE_TOOLS+=		gm4 pkg-config
PKGCONFIG_OVERRIDE=	sigc++.pc.in
PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.mm-common+=	mm-common>=0.9.10
.include "../../devel/mm-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
