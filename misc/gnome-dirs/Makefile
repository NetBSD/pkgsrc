# $NetBSD: Makefile,v 1.2 2003/06/02 01:18:16 jschauma Exp $
#

DISTNAME=	gnome-dirs-${GNOME_DIRS_VERSION}
WRKSRC=		${WRKDIR}
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	# empty
COMMENT=	Shared GTK/GNOME (v1 and v2) directories

NO_BUILD=	# defined
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_EXTRACT=	# defined

USE_BUILDLINK2=	YES
USE_X11BASE=	YES

GNOME_DIRS=	${GNOME_DIRS_COMMON}

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
