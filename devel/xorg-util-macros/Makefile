# $NetBSD: Makefile,v 1.14 2018/03/05 09:22:37 wiz Exp $

DISTNAME=		util-macros-1.19.2
PKGNAME=		xorg-${DISTNAME}
CATEGORIES=		devel x11
MASTER_SITES=		${MASTER_SITE_XORG:=util/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xorg autotool macros
LICENSE=		mit

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	xorg-macros.pc.in

.include "../../mk/bsd.pkg.mk"
