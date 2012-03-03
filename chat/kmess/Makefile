# $NetBSD: Makefile,v 1.48 2012/03/03 00:12:48 wiz Exp $
#

DISTNAME=	kmess-1.4.3
PKGREVISION=	17
CATEGORIES=	chat kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kmess/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kmess.org/
COMMENT=	MSN Messenger Client for KDE3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
SET_LIBDIR=		yes
USE_TOOLS+=		gmake msgfmt perl
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

MAKE_FLAGS+=		KPHONEDIR=${PREFIX}/include

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
