# $NetBSD: Makefile,v 1.2 2017/09/08 09:51:19 jaapb Exp $

VERSION=	0.9.3
GITHUB_PROJECT=	base
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGREVISION=	1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
DIST_SUBDIR=	ocaml-${GITHUB_PROJECT}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/base/
COMMENT=	Alternative standard library for OCaml
LICENSE=	apache-2.0

OCAML_USE_FINDLIB=	yes
OCAML_USE_JBUILDER=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-sexplib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
