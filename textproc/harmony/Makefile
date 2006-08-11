# $NetBSD: Makefile,v 1.1.1.1 2006/08/11 15:55:31 wiz Exp $
#

DISTNAME=	harmony-stable-${VERSION}
PKGNAME=	harmony-${VERSION}
CATEGORIES=	misc
MASTER_SITES=	http://alliance.seas.upenn.edu/~harmony/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://alliance.seas.upenn.edu/~harmony/
COMMENT=	Generic framework for reconciling disconnected updates to heterogeneous, replicated XML data

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
DEPENDS+=	equeue-[0-9]*:../../devel/equeue
DEPENDS+=	ocamlnet-[0-9]*:../../net/ocamlnet
DEPENDS+=	pxp-[0-9]*:../../textproc/pxp

VERSION=20060526

WRKSRC=		${WRKDIR}/harmony-nightly-${VERSION}
USE_TOOLS+=	gmake
TEX_DEPMETHOD=	build
TEST_TARGET=	test

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
		${INSTALL_PROGRAM} ${WRKSRC}/$$file ${PREFIX}/bin; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/harmony
	${INSTALL_DATA} ${WRKSRC}/doc/manual.pdf ${PREFIX}/share/doc/harmony
	${INSTALL_DATA} ${WRKSRC}/doc/main.pdf ${PREFIX}/share/doc/harmony

.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
