# $NetBSD: Makefile,v 1.8 2004/01/20 12:21:02 agc Exp $
#

DISTNAME=	gnome1-dirs-${GNOME_DIRS_VERSION}
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared GTK/GNOME (v1) directories

DEPENDS+=	gnome-dirs>=1.0:../../misc/gnome-dirs

NO_BUILD=	# defined
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_EXTRACT=	# defined

WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	YES
USE_X11BASE=	YES

# No GNOME 1 specific directories yet.
GNOME_DIRS=

.include "../../misc/gnome-dirs/Makefile.common"
.include "../../mk/bsd.pkg.mk"
