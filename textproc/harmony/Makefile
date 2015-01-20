# $NetBSD: Makefile,v 1.15 2015/01/20 14:24:37 jaapb Exp $
#

DISTNAME=	harmony-stable-${VERSION}
PKGNAME=	harmony-${VERSION}
PKGREVISION=	7
CATEGORIES=	misc
MASTER_SITES=	http://alliance.seas.upenn.edu/~harmony/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://alliance.seas.upenn.edu/~harmony/
COMMENT=	Reconciles disconnected updates to heterogeneous, replicated XML data

MAKE_JOBS_SAFE=	no

BUILD_DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
BUILD_DEPENDS+=	tex-bibtex-[0-9]*:../../print/tex-bibtex
BUILD_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
BUILD_DEPENDS+=	tex-preprint-[0-9]*:../../print/tex-preprint
BUILD_DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
DEPENDS+=	pxp-[0-9]*:../../textproc/pxp

VERSION=20060526

WRKSRC=		${WRKDIR}/harmony-nightly-${VERSION}
USE_TOOLS+=	gmake
TEST_TARGET=	test

INSTALLATION_DIRS=	bin share/doc/harmony

do-install:
	for file in src/harmony \
		examples/addresses/harmonize-addresses \
		examples/basics/harmonize-basics \
		examples/bookmarks/harmonize-bookmarks \
		examples/calendars/harmonize-calendars \
		examples/listexamples/harmonize-listexamples \
		examples/plist/harmonize-plist \
		examples/relational/harmonize-relational \
		examples/structuredtext/harmonize-structuredtext; do \
		${INSTALL_PROGRAM} ${WRKSRC}/$$file ${DESTDIR}${PREFIX}/bin; \
	done
	${INSTALL_DATA} ${WRKSRC}/doc/manual.pdf ${DESTDIR}${PREFIX}/share/doc/harmony
	${INSTALL_DATA} ${WRKSRC}/doc/main.pdf ${DESTDIR}${PREFIX}/share/doc/harmony

.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../net/ocamlnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
