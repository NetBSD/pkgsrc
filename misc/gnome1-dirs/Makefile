# $NetBSD: Makefile,v 1.2 2003/01/27 14:14:13 jmmv Exp $
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

GNOME_DIRS=	share/applets/Amusements
GNOME_DIRS+=	share/applets/Clocks
GNOME_DIRS+=	share/applets/Monitors
GNOME_DIRS+=	share/applets/Multimedia
GNOME_DIRS+=	share/applets/Network
GNOME_DIRS+=	share/applets/Utility

.include "../../misc/gnome-dirs/Makefile.common"
.include "../../misc/gnome-dirs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
