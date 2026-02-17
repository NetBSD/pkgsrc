# $NetBSD: Makefile,v 1.16 2026/02/17 13:39:00 wiz Exp $

VERSION=	113.33.06
GITHUB_PROJECT=	js-build-tools
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/js-build-tools/
COMMENT=	OCaml build helper tools from Jane Street
LICENSE=	apache-2.0

HAS_CONFIGURE=		yes
USE_LANGUAGES=		# none
OCAML_USE_FINDLIB=	yes

.include "../../devel/ocaml-oasis/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../misc/ocaml-opam/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
