# $NetBSD: Makefile,v 1.11 2004/01/22 13:17:05 jlam Exp $
#

DISTNAME=	gnome2-dirs-${GNOME_DIRS_VERSION}
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared GTK/GNOME (v2) directories

WRKSRC=		${WRKDIR}
NO_EXTRACT=	# defined
NO_CHECKSUM=	# defined
NO_BUILDLINK=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

.include "../../mk/bsd.prefs.mk"

.if ${X11PREFIX} == ${LOCALBASE}
DEPENDS+=	gnome-dirs>=1.0:../../misc/gnome-dirs
GNOME_DIRS=
.else
GNOME_DIRS=	${GNOME_DIRS_COMMON}
.endif

GNOME_DIRS+=	share/applications
GNOME_DIRS+=	share/application-registry
GNOME_DIRS+=	share/control-center-2.0
GNOME_DIRS+=	share/control-center-2.0/capplets
GNOME_DIRS+=	share/gnome-2.0
GNOME_DIRS+=	share/gnome-2.0/ui
GNOME_DIRS+=	share/gnome/wm-properties

.include "../../misc/gnome-dirs/Makefile.common"
.include "../../mk/bsd.pkg.mk"
