# $NetBSD: Makefile,v 1.18 2004/06/05 00:23:56 xtraeme Exp $
#

DISTNAME=	gnome2-dirs-1.5
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared GTK/GNOME (v2) directories

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
USE_PKGINSTALL=	yes
NO_EXTRACT=	# defined
NO_CHECKSUM=	# defined
NO_BUILDLINK=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

.include "dirs.mk"
.include "../../mk/bsd.prefs.mk"

.if ${X11PREFIX} == ${LOCALBASE}
DEPENDS+=	gnome-dirs>=1.0:../../misc/gnome-dirs
_SORTED!=	${ECHO} ${GNOME2_DIRS} | ${TR} -s ' \t' '\n' | ${SORT}
.else
_SORTED!=	${ECHO} ${GNOME_DIRS} ${GNOME2_DIRS} | ${TR} -s ' \t' '\n' | \
		${SORT}
.endif

MAKE_DIRS+=	${_SORTED:S/^/${LOCALBASE}\//}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
