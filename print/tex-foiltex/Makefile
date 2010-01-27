# $NetBSD: Makefile,v 1.10 2010/01/27 16:15:19 joerg Exp $

DISTNAME=	# empty
PKGNAME=	tex-foiltex-2.1.4a
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/supported/foiltex/}
DISTFILES=	foiltex.dtx foiltex.ins

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tex.ac.uk/tex-archive/help/Catalogue/entries/foiltex.html
COMMENT=	LaTeX2e class for overhead transparencies
LICENSE=	foiltex-license

PKG_DESTDIR_SUPPORT=	user-destdir

RESTRICTED=	May not be redistributed for profit
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

INSTALLATION_DIRS+=	${STYDIR}

do-install:
	cd ${WRKSRC} && for f in foils.* foil*.clo fltfonts.def; do \
		${INSTALL_DATA} $$f ${DESTDIR}${STYDIR}/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
