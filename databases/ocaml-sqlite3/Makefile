# $NetBSD: Makefile,v 1.43 2019/03/05 16:25:25 jaapb Exp $

GITHUB_PROJECT=	sqlite3-ocaml
GITHUB_RELEASE=	${PKGVERSION_NOREV}
DISTNAME=	sqlite3-4.4.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=mmottl/}
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mmottl/sqlite3-ocaml/
COMMENT=	Sqlite bindings for OCaml
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config
OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-configurator/buildlink3.mk"
.include "../../devel/ocaml-stdio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
