# $NetBSD: Makefile,v 1.14 2017/09/06 10:40:32 wiz Exp $

DISTNAME=	# empty
PKGNAME=	tex-foiltex-2.1.4a
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/supported/foiltex/}
DISTFILES=	foiltex.dtx foiltex.ins

MAINTAINER=	minskim@NetBSD.org
#HOMEPAGE=	http://www.tex.ac.uk/tex-archive/help/Catalogue/entries/foiltex.html
COMMENT=	LaTeX2e class for overhead transparencies
LICENSE=	foiltex-license

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

RESTRICTED=	May not be redistributed for profit
NO_BIN_ON_CDROM=${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}

NO_CONFIGURE=	YES

INSTALLATION_DIRS+=	${PREFIX}/share/texmf-dist/tex/latex/foiltex

.include "../../print/kpathsea/texmf.mk"

do-extract:
	for f in ${DISTFILES}; do \
		${CP} ${DISTDIR}/$$f ${WRKSRC}/$$f; \
	done

do-build:
	cd ${WRKSRC} && ${LOCALBASE}/bin/latex foiltex.ins

do-install:
	cd ${WRKSRC} && for f in foils.* foil*.clo fltfonts.def; do \
		${INSTALL_DATA} $$f \
		${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/foiltex/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
