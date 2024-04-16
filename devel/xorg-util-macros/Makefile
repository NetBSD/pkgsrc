# $NetBSD: Makefile,v 1.20 2024/04/16 21:19:27 wiz Exp $

DISTNAME=		util-macros-1.20.1
PKGNAME=		xorg-${DISTNAME}
CATEGORIES=		devel x11
MASTER_SITES=		${MASTER_SITE_XORG:=util/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Xorg autotool macros
LICENSE=		mit

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	xorg-macros.pc.in

.include "../../mk/bsd.pkg.mk"
