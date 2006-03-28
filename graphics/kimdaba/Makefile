# $NetBSD: Makefile,v 1.5 2006/03/28 10:04:29 joerg Exp $
#

DISTNAME=		kimdaba-2.1
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		http://ktown.kde.org/kimdaba/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ktown.kde.org/kimdaba/
COMMENT=		Image organizer

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
BUILD_USES_MSGFMT=	yes

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
