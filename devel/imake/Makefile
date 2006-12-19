# $NetBSD: Makefile,v 1.1.1.1 2006/12/19 22:56:06 joerg Exp $
#

DISTNAME=		imake-1.0.2
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/util/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/releases/individual/util/
COMMENT=		Imake and other utilities from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config makedepend:run

DEPENDS+=		xorg-cf-files-[0-9]*:../../x11/xorg-cf-files

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
