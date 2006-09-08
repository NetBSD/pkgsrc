# $NetBSD: Makefile,v 1.13 2006/09/08 16:27:34 jmmv Exp $
#

DISTNAME=	xdg-x11-dirs-1.4
CATEGORIES=	misc gnome kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared XDG directories under the X11 tree

CONFLICTS=	gnome2-dirs<=1.2

NO_BUILD=	yes
NO_CONFIGURE=	yes
NO_CHECKSUM=	yes
NO_EXTRACT=	yes
USE_LANGUAGES=	# empty
USE_X11BASE=	yes
WRKSRC=		${WRKDIR}

.include "dirs.mk"
.include "../../mk/bsd.prefs.mk"

.if ${X11PREFIX} == ${LOCALBASE}
DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs
.else
REQD_DIRS+=	${XDG_X11_DIRS:O:S/^/${PREFIX}\//}
.endif

do-install:	# nothing

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
