# $NetBSD: Makefile,v 1.29 2017/07/30 22:32:11 wiz Exp $

VERSION=	4.0.5
GITHUB_PROJECT=	sqlite3-ocaml
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-sqlite3-${VERSION}
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=mmottl/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mmottl/sqlite3-ocaml/
COMMENT=	Sqlite bindings for OCaml
LICENSE=	mit

#HAS_CONFIGURE=	yes
#CONFIGURE_ARGS+=	--destdir "${DESTDIR}" --prefix "${PREFIX}"
WRKSRC=	${WRKDIR}/${GITHUB_PROJECT}-${VERSION}

USE_TOOLS+=	gmake pkg-config
OCAML_USE_OASIS=	yes

.include "../../mk/ocaml.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
