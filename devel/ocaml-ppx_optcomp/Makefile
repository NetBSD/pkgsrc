# $NetBSD: Makefile,v 1.4 2016/06/25 14:47:54 jaapb Exp $

VERSION=	113.33.00
GITHUB_PROJECT=	ppx_optcomp
GITHUB_TAG=	${VERSION}+4.03
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_optcomp/
COMMENT=	Optional compilation for OCaml
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME}-4.03
HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none
OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-ppx_core/buildlink3.mk"
.include "../../devel/ocaml-ppx_tools/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
