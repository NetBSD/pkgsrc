# $NetBSD: Makefile,v 1.6 2004/06/05 00:20:05 xtraeme Exp $
#

DISTNAME=	xdg-dirs-1.1
CATEGORIES=	misc gnome kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared XDG directories

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS=	gnome2-dirs<=1.2

NO_BUILD=	# defined
NO_BUILDLINK=	# defined
NO_CONFIGURE=	# defined
NO_CHECKSUM=	# defined
NO_EXTRACT=	# defined
USE_LANGUAGES=	# empty
USE_PKGINSTALL=	yes
WRKSRC=		${WRKDIR}

.include "dirs.mk"
.include "../../mk/bsd.prefs.mk"

_SORTED!=	${ECHO} ${XDG_DIRS} | ${TR} -s ' \t' '\n' | ${SORT}
MAKE_DIRS+=	${_SORTED:S/^/${LOCALBASE}\//}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
