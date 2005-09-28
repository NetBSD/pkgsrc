# $NetBSD: Makefile,v 1.9 2005/09/28 19:51:27 rillig Exp $
#

DISTNAME=	xdg-x11-dirs-1.2
PKGREVISION=	1
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
USE_PKGINSTALL=	yes
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
