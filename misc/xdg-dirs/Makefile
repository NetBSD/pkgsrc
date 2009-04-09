# $NetBSD: Makefile,v 1.19 2009/04/09 00:48:09 joerg Exp $
#

DISTNAME=	xdg-dirs-1.4
CATEGORIES=	misc gnome kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared XDG directories

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	gnome2-dirs<=1.2

NO_BUILD=	yes
NO_CONFIGURE=	yes
PLIST_SRC=	# empty
USE_LANGUAGES=	# empty
WRKSRC=		${WRKDIR}

.include "dirs.mk"
.include "../../mk/bsd.prefs.mk"

REQD_DIRS+=	${XDG_DIRS:O:S/^/${PREFIX}\//}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
