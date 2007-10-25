# $NetBSD: Makefile,v 1.17 2007/10/25 22:01:02 jlam Exp $
#

DISTNAME=	xdg-dirs-1.4
CATEGORIES=	misc gnome kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared XDG directories

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	gnome2-dirs<=1.2

NO_BUILD=	yes
NO_CONFIGURE=	yes
NO_CHECKSUM=	yes
NO_EXTRACT=	yes
PLIST_SRC=	# empty
USE_LANGUAGES=	# empty
WRKSRC=		${WRKDIR}

.include "dirs.mk"
.include "../../mk/bsd.prefs.mk"

REQD_DIRS+=	${XDG_DIRS:O:S/^/${PREFIX}\//}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
