# $NetBSD: Makefile,v 1.1.1.1 2003/01/27 09:36:26 jmmv Exp $
#

DISTNAME=	gnome1-dirs-${GNOME_DIRS_VERSION}
WRKSRC=		${WRKDIR}
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	# empty
COMMENT=	Shared GTK/GNOME (v1) directories

NO_BUILD=	# defined
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_EXTRACT=	# defined

USE_BUILDLINK2=	YES
USE_X11BASE=	YES

# No GNOME 1 specific directories yet.
GNOME_DIRS=

.include "../../misc/gnome-dirs/Makefile.common"
.include "../../misc/gnome-dirs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
