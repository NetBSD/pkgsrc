# $NetBSD: Makefile,v 1.26 2026/03/01 12:38:21 gdt Exp $

VERSION=	3.5.1
GITHUB_PROJECT=	batteries-included
GITHUB_TAG=	v${VERSION}
DISTNAME=	batteries-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-batteries-team/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-batteries-team/batteries-included/
COMMENT=	Alternative standard library for OCaml
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		gmake
OCAML_USE_FINDLIB=	yes

MAKE_ENV=	DESTDIR="${DESTDIR}" PREFIX="${PREFIX}"

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../math/ocaml-num/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
