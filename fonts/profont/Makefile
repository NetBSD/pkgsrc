# $NetBSD: Makefile,v 1.6 2006/02/05 23:09:10 joerg Exp $
#

DISTNAME=	profontlinux
PKGNAME=        profont-1.0
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://www.tobiasjung.net/dl/
EXTRACT_SUFX=	.zip

MAINTAINER=	perry@NetBSD.org
HOMEPAGE=	http://www.tobias-jung.de/seekingprofont/
COMMENT=	Monospaced bitmap font readable in very small sizes

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_X11BASE=		yes

FONTS_DIRS.x11=		${PREFIX}/lib/X11/fonts/misc
INSTALLATION_DIRS=	lib/X11/fonts/misc

do-install:
	for i in ${WRKDIR}/*.pcf; do ${INSTALL_DATA} $$i ${FONTS_DIRS.x11}; done

.include "../../mk/bsd.pkg.mk"
