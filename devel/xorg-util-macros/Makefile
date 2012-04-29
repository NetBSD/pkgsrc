# $NetBSD: Makefile,v 1.8 2012/04/29 10:25:37 wiz Exp $
#

DISTNAME=		util-macros-1.17
PKGNAME=		xorg-${DISTNAME}
CATEGORIES=		devel x11
MASTER_SITES=		${MASTER_SITE_XORG:=util/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xorg autotool macros
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	xorg-macros.pc.in

.include "../../mk/bsd.pkg.mk"
