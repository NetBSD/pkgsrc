# $NetBSD: Makefile,v 1.9 2004/06/05 00:23:56 xtraeme Exp $
#

DISTNAME=	gnome-dirs-1.5
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared GTK/GNOME (v1 and v2) directories

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
USE_PKGINSTALL=	yes
USE_X11BASE=	yes
NO_CHECKSUM=	# defined
NO_EXTRACT=	# defined
NO_BUILDLINK=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

.include "dirs.mk"
.include "../../mk/bsd.prefs.mk"

_SORTED!=	${ECHO} ${GNOME_DIRS} | ${TR} -s ' \t' '\n' | ${SORT}
MAKE_DIRS+=	${_SORTED:S/^/${LOCALBASE}\//}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
