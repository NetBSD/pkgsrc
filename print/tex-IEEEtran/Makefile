# $NetBSD: Makefile,v 1.10 2006/10/04 21:56:34 wiz Exp $
#

DISTNAME=	IEEEtran
PKGNAME=	tex-IEEEtran-1.6c
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	http://www.ieee.org/portal/cms_docs/pubs/transactions/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} IEEEtranBST${EXTRACT_SUFX}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.ieee.org/portal/pages/pubs/transactions/stylesheets.html
COMMENT=	LaTeX class for IEEE journals and conferences

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_DIRS+=	texmf-1.0

LATEX_FILES=	IEEEtran.cls IEEEtran_HOWTO.pdf README \
		bare_conf.tex bare_jrnl.tex
BIB_FILES=	IEEEabrv.bib IEEEbcpat.bib IEEEexample.bib IEEEfull.bib
BST_FILES=	IEEEtran.bst IEEEtranS.bst IEEEtran_bst_HOWTO.pdf

.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/IEEEtran
.for f in ${LATEX_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PKG_LOCALTEXMFPREFIX}/tex/latex/IEEEtran
.endfor
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/bibtex/bib/IEEEtran
.for f in ${BIB_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PKG_LOCALTEXMFPREFIX}/bibtex/bib/IEEEtran
.endfor
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/bibtex/bst/IEEEtran
.for f in ${BST_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PKG_LOCALTEXMFPREFIX}/bibtex/bst/IEEEtran
.endfor

.include "../../mk/bsd.pkg.mk"
