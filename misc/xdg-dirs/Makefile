# $NetBSD: Makefile,v 1.1.1.1 2004/02/04 13:21:19 markd Exp $
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
