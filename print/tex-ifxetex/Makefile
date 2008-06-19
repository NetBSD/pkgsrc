# $NetBSD: Makefile,v 1.1.1.1 2008/06/19 16:24:49 reed Exp $

DISTNAME=	ifxetex
PKGNAME=	tex-${DISTNAME}-0.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/generic/}
EXTRACT_SUFX=	.zip

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://tug.ctan.org/tex-archive/help/Catalogue/entries/ifxetex.html
COMMENT=	TeX package to determine if running under XeTeX

DIST_SUBDIR=	${PKGNAME_NOREV}
INSTALLATION_DIRS=	share/doc/tex-ifxetex
NO_BUILD=	yes
NO_CONFIGURE=	yes
USE_DIRS+=	texmf-1.0

.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/ifxetex
	${INSTALL_DATA} ${WRKSRC}/ifxetex.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/ifxetex/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tex-ifxetex/

.include "../../mk/bsd.pkg.mk"
