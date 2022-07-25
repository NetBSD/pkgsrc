# $NetBSD: Makefile,v 1.17 2022/07/25 11:12:24 wiz Exp $

DISTNAME=		util-macros-1.19.3
PKGNAME=		xorg-${DISTNAME}
CATEGORIES=		devel x11
MASTER_SITES=		${MASTER_SITE_XORG:=util/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Xorg autotool macros
LICENSE=		mit

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	xorg-macros.pc.in

.include "../../mk/bsd.pkg.mk"
