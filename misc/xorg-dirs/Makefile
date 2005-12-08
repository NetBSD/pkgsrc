# $NetBSD: Makefile,v 1.7 2005/12/08 09:52:16 rillig Exp $
#

DISTNAME=	xorg-dirs-1.1
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared X.org directories

NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_EXTRACT=		yes
NO_XORG_TARGETS=	yes
USE_PKGINSTALL=		yes
WRKSRC=			${WRKDIR}

XORG_ONLY_DIRS=		# defined
.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../mk/bsd.prefs.mk"
.include "dirs.mk"

REQD_DIRS+=	${XORG_DIRS:O:S/^/${X11ROOT}\//}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
