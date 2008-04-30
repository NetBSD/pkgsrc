# $NetBSD: Makefile,v 1.29 2008/04/30 13:38:15 jmmv Exp $
#

DISTNAME=	gnome2-dirs-1.6
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared GTK/GNOME (v2) directories

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
NO_EXTRACT=	yes
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	# empty

.include "dirs.mk"
.include "../../mk/bsd.prefs.mk"

.if ${X11PREFIX} == ${LOCALBASE}
DEPENDS+=	gnome-dirs>=1.6:../../misc/gnome-dirs
ALL_GNOME_DIRS=	${GNOME2_DIRS}
.else
ALL_GNOME_DIRS=	${GNOME_DIRS} ${GNOME2_DIRS}
.endif

REQD_DIRS+=	${ALL_GNOME_DIRS:O:S/^/${PREFIX}\//}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
