# $NetBSD: Makefile,v 1.7 2006/04/17 13:46:33 wiz Exp $
#

DISTNAME=		kimdaba-2.1
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		http://ktown.kde.org/kimdaba/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ktown.kde.org/kimdaba/
COMMENT=		Image organizer

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		msgfmt

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
