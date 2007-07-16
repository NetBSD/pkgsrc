# $NetBSD: Makefile,v 1.11 2007/07/16 23:49:07 minskim Exp $
#

DISTNAME=	IEEEtran
PKGNAME=	tex-IEEEtran-1.7
CATEGORIES=	print
MASTER_SITES=	http://www.ieee.org/portal/cms_docs_iportals/iportals/publications/journmag/transactions/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} IEEEtranBST${EXTRACT_SUFX}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.ieee.org/portal/pages/pubs/transactions/stylesheets.html
COMMENT=	LaTeX class for IEEE journals and conferences

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_DIRS+=	texmf-1.4

LATEX_FILES=	IEEEtran.cls
LATEX_DOCS=	IEEEtran_HOWTO.pdf README \
		bare_adv.tex bare_conf.tex bare_jrnl.tex bare_jrnl_compsoc.tex
BIB_FILES=	IEEEabrv.bib IEEEexample.bib IEEEfull.bib
BST_FILES=	IEEEtran.bst IEEEtranS.bst
BIBTEX_DOCS=	IEEEtran_bst_HOWTO.pdf

.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/IEEEtran
.for f in ${LATEX_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PKG_LOCALTEXMFPREFIX}/tex/latex/IEEEtran
.endfor
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/doc/latex/IEEEtran
.for f in ${LATEX_DOCS}
		${INSTALL_DATA} ${WRKSRC}/${f} ${PKG_LOCALTEXMFPREFIX}/doc/latex/IEEEtran
.endfor
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/bibtex/bib/IEEEtran
.for f in ${BIB_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PKG_LOCALTEXMFPREFIX}/bibtex/bib/IEEEtran
.endfor
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/bibtex/bst/IEEEtran
.for f in ${BST_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PKG_LOCALTEXMFPREFIX}/bibtex/bst/IEEEtran
.endfor
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/doc/bibtex/IEEEtran
.for f in ${BIBTEX_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PKG_LOCALTEXMFPREFIX}/doc/bibtex/IEEEtran
.endfor

.include "../../mk/bsd.pkg.mk"
