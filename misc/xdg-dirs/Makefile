# $NetBSD: Makefile,v 1.2 2004/02/15 18:08:03 jmmv Exp $
#

DISTNAME=	xdg-dirs-1.0
CATEGORIES=	misc gnome kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared XDG directories

CONFLICTS=	gnome2-dirs<=1.2

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
NO_EXTRACT=	# defined
NO_CHECKSUM=	# defined
NO_BUILDLINK=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

.include "../../mk/bsd.prefs.mk"

XDG_DIRS=	share/applications

_SORTED!=	${ECHO} ${XDG_DIRS} | ${TR} -s ' \t' '\n' | ${SORT}

USE_PKGINSTALL=	yes
MAKE_DIRS+=	${_SORTED:S/^/${PREFIX}\//}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
