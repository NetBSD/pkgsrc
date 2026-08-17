# $NetBSD: Makefile,v 1.19 2026/08/17 05:38:53 wiz Exp $

DISTNAME=		makedepend-1.0.10
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_XORG:=util/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Dependency generator for make

USE_TOOLS+=		pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
