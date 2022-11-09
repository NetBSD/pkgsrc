# $NetBSD: Makefile,v 1.17 2022/11/09 13:14:10 joerg Exp $

DISTNAME=		bdftopcf-1.1.1
CATEGORIES=		fonts
MASTER_SITES=		https://xorg.freedesktop.org/archive/individual/util/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		BDF to PCF font converter for X11

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
