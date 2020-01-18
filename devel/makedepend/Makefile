# $NetBSD: Makefile,v 1.13 2020/01/18 23:30:34 rillig Exp $

DISTNAME=		makedepend-1.0.6
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_XORG:=util/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Dependency generator for make

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
