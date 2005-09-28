# $NetBSD: Makefile,v 1.10 2005/09/28 19:24:49 rillig Exp $
#

DISTNAME=	XFree86-dirs-1.1
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared XFree86 directories

NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_EXTRACT=		yes
NO_XFREE86_TARGETS=	yes
USE_PKGINSTALL=		yes
WRKSRC=			${WRKDIR}

XFREE86_ONLY_DIRS=	# defined
.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../mk/bsd.prefs.mk"
.include "dirs.mk"

REQD_DIRS+=	${XFREE86_DIRS:O:S/^/${X11ROOT}\//:C/\/\/\/*/\//g}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
