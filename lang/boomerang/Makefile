# $NetBSD: Makefile,v 1.24 2023/06/06 12:41:41 riastradh Exp $
#

DISTNAME=	boomerang-0.2-source
PKGNAME=	${DISTNAME:S/-source//}
PKGREVISION=	17
CATEGORIES=	lang
MASTER_SITES=	http://www.seas.upenn.edu/~harmony/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.seas.upenn.edu/~harmony/
COMMENT=	Bidirectional programming language for ad-hoc, textual data
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	omake-[0-9]*:../../devel/omake
# for pdflatex
TOOL_DEPENDS+=	tex-epstopdf-pkg-[0-9]*:../../print/tex-epstopdf-pkg
TOOL_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TOOL_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
TOOL_DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
TOOL_DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
TOOL_DEPENDS+=	tex-amscls-[0-9]*:../../print/tex-amscls
TOOL_DEPENDS+=	tex-preprint-[0-9]*:../../print/tex-preprint
TOOL_DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
TOOL_DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
TOOL_DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

WRKSRC=			${WRKDIR}/boomerang-20090902
USE_LANGUAGES=		c
INSTALLATION_DIRS=	bin share/doc/boomerang share/examples/boomerang/xsugar
INSTALLATION_DIRS+=	share/examples/boomerang/units

do-build:
	cd ${WRKSRC} && omake

do-install:
	cd ${WRKSRC} && \
	${INSTALL_PROGRAM} bin/boomerang ${DESTDIR}${PREFIX}/bin; \
	${INSTALL_DATA} doc/main.pdf \
		${DESTDIR}${PREFIX}/share/doc/boomerang; \
	${INSTALL_DATA} examples/*.* \
		${DESTDIR}${PREFIX}/share/examples/boomerang; \
	${INSTALL_DATA} examples/OMakefile \
		${DESTDIR}${PREFIX}/share/examples/boomerang; \
	${INSTALL_DATA} examples/units/*.* \
		${DESTDIR}${PREFIX}/share/examples/boomerang/units; \
	${INSTALL_DATA} examples/xsugar/*.* \
		${DESTDIR}${PREFIX}/share/examples/boomerang/xsugar

.include "../../lang/ocaml/buildlink3.mk"
.include "../../math/ocaml-num/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
