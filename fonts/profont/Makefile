# $NetBSD: Makefile,v 1.1 2003/12/20 00:28:12 perry Exp $
#

DISTNAME=	profontlinux
PKGNAME=        profont-1.0
CATEGORIES=	fonts
MASTER_SITES=	http://www.tobiasjung.net/dl/
EXTRACT_SUFX=	.zip

MAINTAINER=	perry@NetBSD.org
HOMEPAGE=	http://www.tobias-jung.de/seekingprofont/
COMMENT=	Monospaced bitmap font readable in very small sizes

USE_BUILDLINK2=		yes
NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_X11BASE=		yes
USE_PKGINSTALL=		yes

FONTS_X11_DIRS=		${PREFIX}/lib/X11/fonts/misc

do-install:
	for i in ${WRKDIR}/*.pcf; do ${INSTALL_DATA} $$i ${FONTS_X11_DIRS}; done

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
