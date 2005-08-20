# $NetBSD: Makefile,v 1.5 2005/08/20 19:16:21 jlam Exp $
#

DISTNAME=	xorg-dirs-1.1
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared X.org directories

NO_BUILD=		# defined
NO_CHECKSUM=		# defined
NO_CONFIGURE=		# defined
NO_EXTRACT=		# defined
NO_XORG_TARGETS=	# defined
USE_PKGINSTALL=		yes
WRKSRC=			${WRKDIR}

XORG_ONLY_DIRS=		# defined
.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../mk/bsd.prefs.mk"
.include "dirs.mk"

REQD_DIRS+=	${XORG_DIRS:O:S/^/${X11ROOT}\//}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
