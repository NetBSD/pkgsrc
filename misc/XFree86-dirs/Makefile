# $NetBSD: Makefile,v 1.13 2006/02/12 15:24:15 xtraeme Exp $
#

DISTNAME=	XFree86-dirs-1.1
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Shared XFree86 directories

NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_EXTRACT=		yes
NO_XFREE86_TARGETS=	yes
WRKSRC=			${WRKDIR}

XFREE86_ONLY_DIRS=	# defined
.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../mk/bsd.prefs.mk"
.include "dirs.mk"

REQD_DIRS+=	${XFREE86_DIRS:O:S/^/${X11ROOT}\//:C/\/\/\/*/\//g}

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
