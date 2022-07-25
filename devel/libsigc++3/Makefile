# $NetBSD: Makefile,v 1.10 2022/07/25 19:22:23 wiz Exp $

DISTNAME=	libsigc++-3.0.7
PKGNAME=	${DISTNAME:S/-/3-/}
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsigc++/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libsigcplusplus/libsigcplusplus
COMMENT=	Type-safe callback system for C++ programs
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		gm4 perl:build pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	sigc++.pc.in

GCC_REQD+=	4.8

.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.mm-common+=	mm-common>=0.9.10
.include "../../devel/mm-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
