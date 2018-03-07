# $NetBSD: Makefile,v 1.12 2018/03/07 11:57:30 wiz Exp $

DISTNAME=		libfontenc-1.1.3
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Library for handling fonts with different character set encodings

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	fontenc.pc.in
GNU_CONFIGURE=		yes

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
