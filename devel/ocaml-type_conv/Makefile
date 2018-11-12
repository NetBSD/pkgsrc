# $NetBSD: Makefile,v 1.16 2018/11/12 16:10:16 jaapb Exp $


VERSION=	113.00.02
GITHUB_PROJECT=	type_conv
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/type_conv/
COMMENT=	Support library for OCaml preprocessor type conversions
LICENSE=	apache-2.0 AND modified-bsd

USE_TOOLS+=	gmake

OCAML_USE_FINDLIB=	yes

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
