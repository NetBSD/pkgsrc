# $NetBSD: Makefile,v 1.26 2009/04/09 00:48:09 joerg Exp $
#

DISTNAME=	gnome1-dirs-1.6
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared GTK/GNOME (v1) directories

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	gnome-dirs>=1.6:../../misc/gnome-dirs

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
USE_X11BASE=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	# empty

.include "dirs.mk"
.include "../../mk/bsd.prefs.mk"

ALL_GNOME_DIRS=	${GNOME_DIRS} ${GNOME1_DIRS}
REQD_DIRS+=	${ALL_GNOME_DIRS:O:S/^/${PREFIX}\//}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
