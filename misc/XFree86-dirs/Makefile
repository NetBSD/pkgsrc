# $NetBSD: Makefile,v 1.8 2005/04/28 22:57:55 jlam Exp $
#

DISTNAME=	XFree86-dirs-1.1
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared XFree86 directories

NO_BUILD=		# defined
NO_CHECKSUM=		# defined
NO_CONFIGURE=		# defined
NO_EXTRACT=		# defined
NO_XFREE86_TARGETS=	# defined
USE_PKGINSTALL=		yes
WRKSRC=			${WRKDIR}

XFREE86_ONLY_DIRS=	# defined
.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../mk/bsd.prefs.mk"
.include "dirs.mk"

MAKE_DIRS+=	${XFREE86_DIRS:O:S/^/${X11ROOT}\//:C/\/\/\/*/\//g}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
