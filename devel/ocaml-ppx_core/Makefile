# $NetBSD: Makefile,v 1.4 2016/06/20 18:48:10 jaapb Exp $

VERSION=	113.33.01
GITHUB_PROJECT=	ppx_core
GITHUB_TAG=	${VERSION}+4.03
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_core/
COMMENT=	Standard library for OCaml ppx rewriters
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${VERSION}-4.03

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

OCAML_USE_FINDLIB=	yes

.include "../../devel/ocaml-oasis/buildlink3.mk"
.include "../../devel/ocaml-ppx_tools/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../misc/ocaml-opam/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
