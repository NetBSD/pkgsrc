# $NetBSD: Makefile,v 1.4 2004/01/20 12:21:01 agc Exp $
#

DISTNAME=	gnome-dirs-${GNOME_DIRS_VERSION}
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared GTK/GNOME (v1 and v2) directories

WRKSRC=		${WRKDIR}
NO_BUILD=	# defined
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_EXTRACT=	# defined

USE_BUILDLINK2=	YES
USE_X11BASE=	YES

GNOME_DIRS=	${GNOME_DIRS_COMMON}

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
