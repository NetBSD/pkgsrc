# $NetBSD: Makefile,v 1.12 2015/07/04 16:18:33 joerg Exp $
#

DISTNAME=	profontlinux
PKGNAME=	profont-1.0
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	http://www.tobiasjung.net/dl/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tobias-jung.de/seekingprofont/
COMMENT=	Monospaced bitmap font readable in very small sizes

NO_BUILD=		yes
NO_CONFIGURE=		yes

FONTS_DIRS.x11=		${PREFIX}/share/fonts/X11/misc
INSTALLATION_DIRS=	share/fonts/X11/misc

do-install:
	for i in ${WRKDIR}/*.pcf; do \
		${INSTALL_DATA} $$i ${DESTDIR}${FONTS_DIRS.x11}; \
	done

.include "../../mk/bsd.pkg.mk"
