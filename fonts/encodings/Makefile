# $NetBSD: Makefile,v 1.14 2024/03/03 10:07:11 wiz Exp $

DISTNAME=		encodings-1.1.0
CATEGORIES=		fonts x11
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X11 Font Index Generator

GNU_CONFIGURE=		yes

USE_TOOLS+=		gzip mkfontscale

.include "../../mk/bsd.pkg.mk"
