# $NetBSD: Makefile,v 1.22 2016/05/05 11:45:37 jaapb Exp $

PKGNAME=	ocaml-sqlite3-${VERSION}
DISTNAME=	v${VERSION}
VERSION=	2.0.6
PKGREVISION=	6
CATEGORIES=	databases
MASTER_SITES=	http://github.com/mmottl/sqlite3-ocaml/archive/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://github.com/mmottl/sqlite3-ocaml/
COMMENT=	Sqlite bindings for OCaml
LICENSE=	mit

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--destdir "${DESTDIR}" --prefix "${PREFIX}"
WRKSRC=	${WRKDIR}/sqlite3-ocaml-${VERSION}

USE_TOOLS+=	gmake pkg-config
OCAML_USE_OASIS=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
