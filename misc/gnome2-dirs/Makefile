# $NetBSD: Makefile,v 1.1.1.1 2003/01/27 09:37:14 jmmv Exp $
#

DISTNAME=	gnome2-dirs-${GNOME_DIRS_VERSION}
WRKSRC=		${WRKDIR}
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	# empty
COMMENT=	Shared GTK/GNOME (v2) directories

NO_BUILD=	# defined
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_EXTRACT=	# defined

USE_BUILDLINK2=	YES

.include "../../mk/bsd.prefs.mk"

.if ${X11PREFIX} == ${LOCALBASE}
.include "../../misc/gnome-dirs/buildlink2.mk"
GNOME_DIRS=
.else
GNOME_DIRS=	${GNOME_DIRS_COMMON}
.endif

GNOME_DIRS+=	share/gnome-2.0
GNOME_DIRS+=	share/gnome-2.0/ui

.include "../../misc/gnome-dirs/Makefile.common"
.include "../../mk/bsd.pkg.mk"
