# $NetBSD: Makefile,v 1.1.1.1 2010/06/02 19:00:36 drochner Exp $
#

DISTNAME=	urw-fonts
PKGNAME=	urw-fonts-1
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/fonts/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.gimp.org/pub/gimp/fonts/
COMMENT=	Standard postscript fonts
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/URW
USE_LANGUAGES=	# none
NO_BUILD=	yes
FONTS_DIR=	${PREFIX}/share/fonts/urw
INSTALLATION_DIRS= share/fonts/urw

do-install:
	for ext in afm pfb pfm; \
	do \
		for f in ${WRKSRC}/*.$${ext}; \
		do \
			${INSTALL_DATA} $${f} ${DESTDIR}${FONTS_DIR}; \
		done; \
	done

.include "../../mk/bsd.pkg.mk"
