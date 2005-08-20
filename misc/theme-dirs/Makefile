# $NetBSD: Makefile,v 1.5 2005/08/20 19:16:21 jlam Exp $
#

DISTNAME=	theme-dirs-1.1
PKGREVISION=	1
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

REQD_DIRS+=	${THEME_DIRS:O:S/^/${PREFIX}\//}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
