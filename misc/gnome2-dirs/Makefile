# $NetBSD: Makefile,v 1.25 2006/02/05 23:10:09 joerg Exp $
#

DISTNAME=	gnome2-dirs-1.5
PKGREVISION=	2
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared GTK/GNOME (v2) directories

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
NO_EXTRACT=	yes
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "dirs.mk"
.include "../../mk/bsd.prefs.mk"

.if ${X11PREFIX} == ${LOCALBASE}
DEPENDS+=	gnome-dirs>=1.0:../../misc/gnome-dirs
ALL_GNOME_DIRS=	${GNOME2_DIRS}
.else
ALL_GNOME_DIRS=	${GNOME_DIRS} ${GNOME2_DIRS}
.endif

REQD_DIRS+=	${ALL_GNOME_DIRS:O:S/^/${PREFIX}\//}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
