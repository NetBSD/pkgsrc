# $NetBSD: Makefile,v 1.12 2008/12/07 06:43:22 minskim Exp $
#

DISTNAME=	IEEEtran
PKGNAME=	tex-IEEEtran-1.7a
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.michaelshell.org/tex/ieeetran/
COMMENT=	LaTeX class for IEEE journals and conferences

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
NO_BUILD=	yes

TEXMFDIRS=	${TEXMFDIST}

.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXMFDIST}/bibtex/bib/${DISTNAME}
	${FIND} ${WRKSRC} -name \*.bib -exec ${INSTALL_DATA} {} \
		${DESTDIR}${TEXMFDIST}/bibtex/bib/${DISTNAME} \;
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXMFDIST}/bibtex/bst/${DISTNAME}
	${FIND} ${WRKSRC} -name \*.bst -exec ${INSTALL_DATA} {} \
		${DESTDIR}${TEXMFDIST}/bibtex/bst/${DISTNAME} \;
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXMFDIST}/doc/latex/${DISTNAME}
	${FIND} ${WRKSRC} -name \*.pdf -exec ${INSTALL_DATA} {} \
		${DESTDIR}${TEXMFDIST}/doc/latex/${DISTNAME} \;
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${TEXMFDIST}/doc/latex/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/bibtex/README \
		${DESTDIR}${TEXMFDIST}/doc/latex/${DISTNAME}/README.bibtex
	${INSTALL_DATA} ${WRKSRC}/extras/README \
		${DESTDIR}${TEXMFDIST}/doc/latex/${DISTNAME}/README.extras
	${INSTALL_DATA} ${WRKSRC}/testflow/README \
		${DESTDIR}${TEXMFDIST}/doc/latex/${DISTNAME}/README.testflow
	${INSTALL_DATA} ${WRKSRC}/tools/README \
		${DESTDIR}${TEXMFDIST}/doc/latex/${DISTNAME}/README.tools
	${FIND} ${WRKSRC} -name \*.txt -exec ${INSTALL_DATA} {} \
		${DESTDIR}${TEXMFDIST}/doc/latex/${DISTNAME} \;
	${FIND} ${WRKSRC} -name \*.tex -exec ${INSTALL_DATA} {} \
		${DESTDIR}${TEXMFDIST}/doc/latex/${DISTNAME} \;
	${FIND} ${WRKSRC} -name \*.eps -exec ${INSTALL_DATA} {} \
		${DESTDIR}${TEXMFDIST}/doc/latex/${DISTNAME} \;
	${INSTALL_DATA_DIR} ${DESTDIR}${TEXMFDIST}/tex/latex/${DISTNAME}
	${FIND} ${WRKSRC} -name \*.cls -exec ${INSTALL_DATA} {} \
		${DESTDIR}${TEXMFDIST}/tex/latex/${DISTNAME} \;
	${FIND} ${WRKSRC} -name \*.sty -exec ${INSTALL_DATA} {} \
		${DESTDIR}${TEXMFDIST}/tex/latex/${DISTNAME} \;

.include "../../mk/bsd.pkg.mk"
