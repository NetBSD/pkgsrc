# $NetBSD: Makefile,v 1.33 2017/11/30 16:45:18 adam Exp $

VERSION=	4.3.0
GITHUB_PROJECT=	sqlite3-ocaml
GITHUB_RELEASE=	${VERSION}
DISTNAME=	sqlite3-${VERSION}
PKGNAME=	ocaml-sqlite3-${VERSION}
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=mmottl/}
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mmottl/sqlite3-ocaml/
COMMENT=	Sqlite bindings for OCaml
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config
OCAML_USE_JBUILDER=	yes

.include "../../mk/ocaml.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-configurator/buildlink3.mk"
.include "../../devel/ocaml-stdio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
