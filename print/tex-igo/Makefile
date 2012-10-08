# $NetBSD: Makefile,v 1.5 2012/10/08 13:45:47 asau Exp $

DISTNAME=	igo
PKGNAME=	tex-${DISTNAME}-0
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=fonts/}
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.ctan.org/tex-archive/fonts/igo/
COMMENT=	Fonts and macro to typeset Go diagrams

BUILD_DEPENDS+=	kpathsea-[0-9]*:../../print/kpathsea
BUILD_DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
BUILD_DEPENDS+=	tex-metafont-[0-9]*:../../fonts/tex-metafont

.include "../../print/kpathsea/texmf.mk"

do-configure:
	${GREP} "^maketfm" ${WRKSRC}/fonts/makefonts.bat | \
	${SED} -e 's,maketfm,${LOCALBASE}/bin/mktextfm,g' \
		> ${WRKSRC}/fonts/makefonts.sh

do-build:
	cd ${WRKSRC}/fonts && ${SH} makefonts.sh

INSTALLATION_DIRS+=	${PREFIX}/share/texmf-dist/doc/latex/igo \
			${PREFIX}/share/texmf-dist/tex/latex/igo \
			${PREFIX}/share/texmf-dist/fonts/source/igo \
			${PREFIX}/share/texmf-dist/fonts/tfm/igo

do-install:
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/igo.pdf ${WRKSRC}/igo.tex \
	    ${DESTDIR}${PREFIX}/share/texmf-dist/doc/latex/igo
	${INSTALL_DATA} ${WRKSRC}/igo.sty ${WRKSRC}/repeat.tex \
	    ${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/igo
	${INSTALL_DATA} ${WRKSRC}/fonts/*.mf \
	    ${DESTDIR}${PREFIX}/share/texmf-dist/fonts/source/igo
	${INSTALL_DATA} ${WRKSRC}/fonts/*.tfm \
	    ${DESTDIR}${PREFIX}/share/texmf-dist/fonts/tfm/igo

.include "../../mk/bsd.pkg.mk"
