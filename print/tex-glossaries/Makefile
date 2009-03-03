# $NetBSD: Makefile,v 1.3 2009/03/03 15:19:26 jmmv Exp $

DISTNAME=	glossaries
PKGNAME=	tex-${DISTNAME}-1.02
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.ctan.org/tex-archive/help/Catalogue/entries/glossaries.html
COMMENT=	Macros for creation of glossaries

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	tex-xkeyval>=2.5f:../../print/tex-xkeyval

DIST_SUBDIR=	${PKGNAME_NOREV}
USE_DIRS+=	texmf-1.4
USE_TOOLS+=	perl:run

REPLACE_PERL=	scripts/makeglossaries

INSTALLATION_DIRS=	bin

.include "../../print/teTeX/module.mk"

do-build:
	cd ${WRKSRC} && latex glossaries.ins

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/makeglossaries \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/doc/latex/glossaries
	${INSTALL_DATA} ${WRKSRC}/doc/glossaries.pdf \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/doc/latex/glossaries
	${INSTALL_DATA_DIR} \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/glossaries
	${INSTALL_DATA} ${WRKSRC}/glossaries.sty \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/glossaries
	${INSTALL_DATA} ${WRKSRC}/glossary-hypernav.sty \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/glossaries
	${INSTALL_DATA} ${WRKSRC}/glossary-list.sty \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/glossaries
	${INSTALL_DATA} ${WRKSRC}/glossary-long.sty \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/glossaries
	${INSTALL_DATA} ${WRKSRC}/glossary-super.sty \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/glossaries

.include "../../mk/bsd.pkg.mk"
