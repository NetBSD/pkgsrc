# $NetBSD: Makefile,v 1.62 2016/02/26 10:24:12 jperkin Exp $
#

DISTNAME=	krusader-1.90.0
PKGREVISION=	36
CATEGORIES=	kde sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=krusader/}

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://krusader.sourceforge.net/
COMMENT=	Advanced twin-panel (commander-style) file-manager for KDE 3.x

USE_TOOLS+=	gmake perl msgfmt
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
SET_LIBDIR=	YES

SHLIBTOOL_OVERRIDE=	# empty

CONFIGURE_ARGS.DragonFly+= --without-acl

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
