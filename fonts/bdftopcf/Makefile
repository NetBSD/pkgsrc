# $NetBSD: Makefile,v 1.18 2024/10/13 07:36:55 wiz Exp $

DISTNAME=		bdftopcf-1.1.2
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
