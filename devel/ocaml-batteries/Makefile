# $NetBSD: Makefile,v 1.18 2018/11/12 16:10:18 jaapb Exp $

VERSION=	2.8.0
GITHUB_PROJECT=	batteries-included
GITHUB_TAG=	v${VERSION}
DISTNAME=	batteries-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-batteries-team/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://batteries.forge.ocamlcore.org/
COMMENT=	Alternative standard library for OCaml
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake
OCAML_USE_FINDLIB=	yes

MAKE_ENV=	DESTDIR="${DESTDIR}" PREFIX="${PREFIX}"

.include "../../mk/ocaml.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../math/ocaml-num/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
