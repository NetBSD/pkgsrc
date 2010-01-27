# $NetBSD: Makefile,v 1.3 2010/01/27 16:22:49 joerg Exp $

DISTNAME=	igo
PKGNAME=	tex-${DISTNAME}-0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=fonts/}
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.ctan.org/tex-archive/fonts/igo/
COMMENT=	Fonts and macro to typeset Go diagrams

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../print/teTeX/module.mk"

do-configure:
	${GREP} "^maketfm" ${WRKSRC}/fonts/makefonts.bat | \
	${SED} -e 's/maketfm/mktextfm/g' > ${WRKSRC}/fonts/makefonts.sh

do-build:
	cd ${WRKSRC}/fonts && ${SH} makefonts.sh

INSTALLATION_DIRS+=	${PKG_LOCALTEXMFPREFIX}/doc/latex/igo \
			${PKG_LOCALTEXMFPREFIX}/tex/latex/igo \
			${PKG_LOCALTEXMFPREFIX}/fonts/source/igo \
			${PKG_LOCALTEXMFPREFIX}/fonts/tfm/igo

do-install:
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/igo.pdf ${WRKSRC}/igo.tex \
	    ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/doc/latex/igo
	${INSTALL_DATA} ${WRKSRC}/igo.sty ${WRKSRC}/repeat.tex \
	    ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/igo
	${INSTALL_DATA} ${WRKSRC}/fonts/*.mf \
	    ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/fonts/source/igo
	${INSTALL_DATA} ${WRKSRC}/fonts/*.tfm \
	    ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/fonts/tfm/igo

.include "../../mk/bsd.pkg.mk"
