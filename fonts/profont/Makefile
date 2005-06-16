# $NetBSD: Makefile,v 1.3 2005/06/16 06:57:52 jlam Exp $
#

DISTNAME=	profontlinux
PKGNAME=        profont-1.0
CATEGORIES=	fonts
MASTER_SITES=	http://www.tobiasjung.net/dl/
EXTRACT_SUFX=	.zip

MAINTAINER=	perry@NetBSD.org
HOMEPAGE=	http://www.tobias-jung.de/seekingprofont/
COMMENT=	Monospaced bitmap font readable in very small sizes

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_X11BASE=		yes
USE_PKGINSTALL=		yes

FONTS_X11_DIRS=		${PREFIX}/lib/X11/fonts/misc
INSTALLATION_DIRS=	lib/X11/fonts/misc

do-install:
	for i in ${WRKDIR}/*.pcf; do ${INSTALL_DATA} $$i ${FONTS_X11_DIRS}; done

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
