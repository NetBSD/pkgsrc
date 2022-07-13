# $NetBSD: Makefile,v 1.11 2022/07/13 20:51:20 wiz Exp $

DISTNAME=		encodings-1.0.6
CATEGORIES=		fonts x11
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X11 Font Index Generator

GNU_CONFIGURE=		yes

USE_TOOLS+=		gzip mkfontscale

.include "../../mk/bsd.pkg.mk"
