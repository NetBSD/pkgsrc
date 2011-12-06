# $NetBSD: Makefile,v 1.5 2011/12/06 00:19:25 sbd Exp $
#

DISTNAME=	harmony-stable-${VERSION}
PKGNAME=	harmony-${VERSION}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://alliance.seas.upenn.edu/~harmony/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://alliance.seas.upenn.edu/~harmony/
COMMENT=	Generic framework for reconciling disconnected updates to heterogeneous, replicated XML data

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

BUILD_DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
DEPENDS+=	equeue-[0-9]*:../../devel/equeue
DEPENDS+=	ocamlnet-[0-9]*:../../net/ocamlnet
DEPENDS+=	pxp-[0-9]*:../../textproc/pxp

VERSION=20060526

WRKSRC=		${WRKDIR}/harmony-nightly-${VERSION}
USE_TOOLS+=	gmake
TEX_DEPMETHOD=	build
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
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
