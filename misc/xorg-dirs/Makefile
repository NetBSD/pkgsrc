# $NetBSD: Makefile,v 1.1.1.1 2004/07/29 07:26:03 xtraeme Exp $
#

DISTNAME=	xorg-dirs-1.0
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared X.org directories

NO_BUILD=		# defined
NO_BUILDLINK=		# defined
NO_CHECKSUM=		# defined
NO_CONFIGURE=		# defined
NO_EXTRACT=		# defined
NO_XORG_TARGETS=	# defined
USE_PKGINSTALL=		yes
WRKSRC=			${WRKDIR}

XORG_ONLY_DIRS=		# defined
.include "../../mk/bsd.prefs.mk"
.include "dirs.mk"

_SORTED!=	${ECHO} ${XORG_DIRS} | ${TR} -s ' \t' '\n' | ${SORT}
MAKE_DIRS+=	${_SORTED:S/^/${X11ROOT}\//}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
