# $NetBSD: Makefile,v 1.13 2004/03/12 20:44:16 jmmv Exp $
#

DISTNAME=	gnome1-dirs-${GNOME_DIRS_VERSION}
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared GTK/GNOME (v1) directories

DEPENDS+=	gnome-dirs>=1.0:../../misc/gnome-dirs
DEPENDS+=	xdg-x11-dirs>=1.1:../../misc/xdg-x11-dirs

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
NO_CHECKSUM=	# defined
NO_EXTRACT=	# defined
NO_BUILDLINK=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

USE_X11BASE=	YES

# No GNOME 1 specific directories yet.
GNOME_DIRS=

.include "../../misc/gnome-dirs/Makefile.common"
.include "../../mk/bsd.pkg.mk"
