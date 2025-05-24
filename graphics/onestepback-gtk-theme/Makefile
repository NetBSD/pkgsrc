# $NetBSD: Makefile,v 1.1 2025/05/24 00:30:20 nia Exp $

DISTNAME=	OneStepBack-v0.997
PKGNAME=	${DISTNAME:tl:S,-v,-gtk-theme-,1}
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.vide.memoire.free.fr/pages/onestepback/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vide.memoire.free.fr/pages/onestepback/onestepback.php
COMMENT=	Gtk theme inspired by NeXTSTEP
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/OneStepBack
NO_BUILD=	yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/themes/OneStepBack

do-install:
.for file in LICENSE README index.theme
	cd ${WRKSRC}/${dir} && ${INSTALL_DATA} ${file} \
	    ${DESTDIR}${PREFIX}/share/themes/OneStepBack/${file}
.endfor
.for dir in gtk-2.0 gtk-3.0 gtk-4.0 img
	${INSTALL_DATA_DIR} \
	    ${DESTDIR}${PREFIX}/share/themes/OneStepBack/${dir}
	cd ${WRKSRC}/${dir} && ${INSTALL_DATA} * \
	    ${DESTDIR}${PREFIX}/share/themes/OneStepBack/${dir}
.endfor

.include "../../mk/bsd.pkg.mk"
