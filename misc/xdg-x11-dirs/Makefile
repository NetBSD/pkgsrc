# $NetBSD: Makefile,v 1.7 2005/06/01 18:03:05 jlam Exp $
#

DISTNAME=	xdg-x11-dirs-1.2
CATEGORIES=	misc gnome kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared XDG directories under the X11 tree

CONFLICTS=	gnome2-dirs<=1.2

NO_BUILD=	# defined
NO_CONFIGURE=	# defined
NO_CHECKSUM=	# defined
NO_EXTRACT=	# defined
USE_LANGUAGES=	# empty
USE_PKGINSTALL=	yes
USE_X11BASE=	yes
WRKSRC=		${WRKDIR}

.include "dirs.mk"
.include "../../mk/bsd.prefs.mk"

.if ${X11PREFIX} == ${LOCALBASE}
DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs
.else
MAKE_DIRS+=	${XDG_X11_DIRS:O:S/^/${PREFIX}\//}
.endif

do-install:	# nothing

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
