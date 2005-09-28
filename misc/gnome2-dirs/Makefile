# $NetBSD: Makefile,v 1.23 2005/09/28 19:51:27 rillig Exp $
#

DISTNAME=	gnome2-dirs-1.5
PKGREVISION=	1
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared GTK/GNOME (v2) directories

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
USE_PKGINSTALL=	yes
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
