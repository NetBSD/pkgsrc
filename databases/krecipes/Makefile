# $NetBSD: Makefile,v 1.14 2008/01/11 12:01:46 drochner Exp $
#

DISTNAME=		krecipes-1.0-beta1
PKGNAME=		krecipes-1.0beta1
PKGREVISION=		2
CATEGORIES=		databases kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=krecipes/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://krecipes.sourceforge.net/
COMMENT=		Recipe manager

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt

CONFIGURE_ARGS+=	--without-mysql --without-postgresql

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
