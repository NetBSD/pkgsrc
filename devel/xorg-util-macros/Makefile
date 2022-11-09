# $NetBSD: Makefile,v 1.18 2022/11/09 13:14:10 joerg Exp $

DISTNAME=		util-macros-1.19.3
PKGNAME=		xorg-${DISTNAME}
CATEGORIES=		devel x11
MASTER_SITES=		${MASTER_SITE_XORG:=util/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Xorg autotool macros
LICENSE=		mit

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	xorg-macros.pc.in

.include "../../mk/bsd.pkg.mk"
