# $NetBSD: Makefile,v 1.1 2021/11/06 11:50:16 rhialto Exp $
#

PKGNAME=		UFAS-otf-${DDATE}
DDATE=			20200320
# Date taken from distfiles; aka version 13.00.
CATEGORIES=		fonts
DIST_SUBDIR=		${PKGNAME_NOREV}
MASTER_SITES=		https://dn-works.com/wp-content/uploads/2020/UFAS-Fonts/
SITES.License.pdf=	https://dn-works.com/wp-content/uploads/2020/UFAS-Docs/
DISTFILES=		Aegean.zip
DISTFILES+=		Aegyptus.zip
DISTFILES+=		Akkadian.zip
DISTFILES+=		Assyrian.zip
DISTFILES+=		Cretan%20Hieroglyphs.zip
DISTFILES+=		Cypro-Minoan%20Inscriptions.zip
DISTFILES+=		EEMusic.zip
DISTFILES+=		Linear%20A%20Inscriptions.zip
DISTFILES+=		Maya%20Hieroglyphs.zip
DISTFILES+=		Textfonts.zip
DISTFILES+=		Unidings.zip
DISTFILES+=		License.pdf

EXTRACT_SUFX=	.zip
EXTRACT_DIR=	${WRKSRC}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dn-works.com/ufas/
COMMENT=	Various Unicode fonts by George Duros
#LICENSE=	In lieu of a licence: Free use of UFAS is strictly limited to personal use. https://dn-works.com/wp-content/uploads/2020/UFAS-Docs/License.pdf

USE_LANGUAGES=	# none
NO_BUILD=	yes
NO_CONFIGURE=	yes

FONTDIR=	${PREFIX}/share/fonts/X11/OTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	${FONTDIR} share/doc/UFAS-otf

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.otf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pdf ${DESTDIR}${PREFIX}/share/doc/UFAS-otf

.include "../../mk/bsd.pkg.mk"
