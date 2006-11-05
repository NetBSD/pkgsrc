# $NetBSD: Makefile,v 1.18 2006/11/05 17:24:31 joerg Exp $
#

DISTNAME=	gnome-dirs-1.6
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared GTK/GNOME (v1 and v2) directories

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
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
