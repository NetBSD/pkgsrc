# $NetBSD: Makefile,v 1.21 2026/11/18 08:07:56 wiz Exp $

DISTNAME=		libfontenc-1.1.10
CATEGORIES=		fonts x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Library for handling fonts with different character set encodings

USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	output/meson-private/fontenc.pc

PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "../../devel/meson/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
