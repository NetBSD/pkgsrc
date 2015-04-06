# $NetBSD: Makefile,v 1.18 2015/04/06 08:17:23 adam Exp $

PKGNAME=	ocaml-sqlite3-${VERSION}
DISTNAME=	v${VERSION}
VERSION=	2.0.6
PKGREVISION=	2
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
