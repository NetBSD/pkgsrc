# $NetBSD: Makefile,v 1.4 2018/01/10 14:41:10 jaapb Exp $

VERSION=	0.10.0
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
