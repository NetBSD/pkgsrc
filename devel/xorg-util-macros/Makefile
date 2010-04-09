# $NetBSD: Makefile,v 1.7 2010/04/09 09:31:34 tnn Exp $
#

DISTNAME=		util-macros-1.7.0
PKGNAME=		xorg-${DISTNAME}
CATEGORIES=		devel x11
MASTER_SITES=		${MASTER_SITE_XORG:=util/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xorg autotool macros

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	xorg-macros.pc.in

.include "../../mk/bsd.pkg.mk"
