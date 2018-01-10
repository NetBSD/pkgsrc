# $NetBSD: Makefile,v 1.3 2018/01/10 16:10:33 jaapb Exp $

VERSION=	0.10.0
GITHUB_PROJECT=	stdio
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/stdio/
COMMENT=	Standard IO library for OCaml
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
OCAML_USE_FINDLIB=	yes
OCAML_USE_JBUILDER=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-sexplib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
