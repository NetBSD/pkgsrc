# $NetBSD: Makefile,v 1.1 2026/10/24 19:03:12 alnsn Exp $

DISTNAME=	unionFind-20220122
PKGNAME=	ocaml-${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.inria.fr/fpottier/unionFind/-/archive/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.inria.fr/fpottier/unionFind/
COMMENT=	Implementations of the union-find data structure for OCaml
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME:tl}-77e9aa955eab31718cc912ea212d32ff087f16ed

USE_LANGUAGES=		# none
OCAML_USE_DUNE=		yes
OPAM_INSTALL_FILES=	unionFind

USE_TOOLS+=	gmake:test
TEST_TARGET=	test

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
