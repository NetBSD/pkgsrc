# $NetBSD: Makefile,v 1.14 2017/09/08 09:51:20 jaapb Exp $

VERSION=	2.7.0
GITHUB_PROJECT=	batteries-included
GITHUB_TAG=	v${VERSION}
DISTNAME=	batteries-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
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
.include "../../mk/bsd.pkg.mk"
