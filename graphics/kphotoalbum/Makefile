# $NetBSD: Makefile,v 1.2 2006/05/25 11:34:45 markd Exp $
#

DISTNAME=		kphotoalbum-2.2
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

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
