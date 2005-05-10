# $NetBSD: Makefile,v 1.4 2005/05/10 20:21:57 jmmv Exp $
#

DISTNAME=	theme-dirs-1.1
CATEGORIES=	misc gnome kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared theme directories

NO_BUILD=	# defined
NO_CONFIGURE=	# defined
NO_CHECKSUM=	# defined
NO_EXTRACT=	# defined
USE_DIRS=	xdg-1.1
USE_LANGUAGES=	# empty
USE_PKGINSTALL=	yes
WRKSRC=		${WRKDIR}

.include "dirs.mk"
.include "../../mk/bsd.prefs.mk"

MAKE_DIRS+=	${THEME_DIRS:O:S/^/${PREFIX}\//}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
