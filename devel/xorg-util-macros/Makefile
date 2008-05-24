# $NetBSD: Makefile,v 1.3 2008/05/24 21:45:20 tnn Exp $
#

DISTNAME=		util-macros-1.1.5
PKGNAME=		xorg-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel x11
MASTER_SITES=		${MASTER_SITE_XORG:=util/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xorg autotool macros

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../mk/bsd.pkg.mk"
