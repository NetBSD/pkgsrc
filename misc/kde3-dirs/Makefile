# $NetBSD: Makefile,v 1.3 2009/04/09 00:48:09 joerg Exp $
#

DISTNAME=	kde3-dirs-1.0
CATEGORIES=	misc kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared KDE (v3) directories

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	# empty

.include "dirs.mk"
.include "../../mk/bsd.prefs.mk"

REQD_DIRS+=	${KDE3_DIRS:O:S/^/${PREFIX}\//}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
