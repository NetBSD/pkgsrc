# $NetBSD: Makefile,v 1.5 2005/04/19 13:06:49 wiz Exp $
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
_SORTED!=	${ECHO} ${XDG_X11_DIRS} | ${TR} -s ' \t' '\n' | ${SORT}
MAKE_DIRS+=	${_SORTED:S/^/${PREFIX}\//}
.endif

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
