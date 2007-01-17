# $NetBSD: Makefile,v 1.4 2007/01/17 23:47:20 wiz Exp $
#

DISTNAME=		kphotoalbum-2.2
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://ktown.kde.org/kphotoalbum/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ktown.kde.org/kphotoalbum/
COMMENT=		Image organizer

CONFLICTS+=		kimdaba-*

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_TOOLS+=		msgfmt

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
