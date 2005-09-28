# $NetBSD: Makefile,v 1.14 2005/09/28 19:51:27 rillig Exp $
#

DISTNAME=	gnome-dirs-1.5
PKGREVISION=	1
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared GTK/GNOME (v1 and v2) directories

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
USE_PKGINSTALL=	yes
USE_X11BASE=	yes
NO_CHECKSUM=	yes
NO_EXTRACT=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "dirs.mk"
.include "../../mk/bsd.prefs.mk"

REQD_DIRS+=	${GNOME_DIRS:O:S/^/${PREFIX}\//}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
