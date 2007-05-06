# $NetBSD: Makefile,v 1.3 2007/05/06 15:00:57 heinz Exp $
#

DISTNAME=		imake-1.0.2
PKGREVISION=		1
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/util/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/releases/individual/util/
COMMENT=		Imake and other utilities from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config makedepend:run

DEPENDS+=		xorg-cf-files>=1.0.2nb1:../../x11/xorg-cf-files

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1 LIB_MAN_SUFFIX=3 FILE_MAN_SUFFIX=5

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
