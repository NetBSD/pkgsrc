# $NetBSD: Makefile,v 1.10 2004/01/20 12:21:02 agc Exp $
#

DISTNAME=	gnome2-dirs-${GNOME_DIRS_VERSION}
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared GTK/GNOME (v2) directories

NO_BUILD=	# defined
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_EXTRACT=	# defined

WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	YES

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
