# $NetBSD: Makefile,v 1.26 2026/02/17 13:38:53 wiz Exp $
#

DISTNAME=	caml${GITHUB_PROJECT}-1.3
PKGNAME=	${DISTNAME:S/caml/ocaml-/}
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}
GITHUB_PROJECT=	dbm
GITHUB_TAG=	camldbm-${PKGVERSION_NOREV}
DIST_SUBDIR=	ocaml-

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/dbm/
COMMENT=	OCaml binding to the NDBM and GDBM database library
LICENSE=	gnu-lgpl-v2

CONFLICTS=	ocaml-findlib<1.4nb1

HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
MAKE_ENV+=		HAS_OCAMLOPT="${OCAML_USE_OPT_COMPILER}" \
			STUBLIBDIR="${DESTDIR}${PREFIX}/lib/ocaml/site-lib/dbm" \
			LIBDIR="${DESTDIR}${PREFIX}/lib/ocaml/site-lib/dbm"

post-install:
	${INSTALL_DATA} ${WRKSRC}/META ${DESTDIR}${PREFIX}/lib/ocaml/site-lib/dbm

.include "../../databases/gdbm/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
