# $NetBSD: Makefile,v 1.64 2026/01/07 08:46:12 wiz Exp $

DISTNAME=	sqlite3-5.1.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=mmottl/}
GITHUB_PROJECT=	sqlite3-ocaml
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mmottl/sqlite3-ocaml/
COMMENT=	Sqlite bindings for OCaml
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-stdio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
