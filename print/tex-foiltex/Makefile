# $NetBSD: Makefile,v 1.4 2006/02/05 23:10:40 joerg Exp $

DISTNAME=	# empty
PKGNAME=	tex-foiltex-2.1.4a
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/supported/foiltex/}
DISTFILES=	foiltex.dtx foiltex.ins

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tex.ac.uk/tex-archive/help/Catalogue/entries/foiltex.html
COMMENT=	LaTeX2e class for overhead transparencies

RESTRICTED=	"May not be redistributed for profit"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}

NO_CONFIGURE=	YES

EVAL_PREFIX+=	LATEX_PREFIX=latex
LATEX_PREFIX_DEFAULT=${LOCALBASE}

STYDIR=		${PKG_LOCALTEXMFPREFIX}/tex/latex/foiltex

.include "../../print/teTeX/module.mk"

do-extract:
	for f in ${DISTFILES}; do \
		${CP} ${DISTDIR}/$$f ${WRKSRC}/$$f; \
	done

do-build:
	cd ${WRKSRC} && ${LATEX_PREFIX}/bin/latex foiltex.ins

do-install:
	${INSTALL_DATA_DIR} ${STYDIR}
	cd ${WRKSRC} && for f in foils.* foil*.clo fltfonts.def; do \
		${INSTALL_DATA} $$f ${STYDIR}/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
