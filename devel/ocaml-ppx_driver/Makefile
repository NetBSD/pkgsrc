# $NetBSD: Makefile,v 1.7 2017/07/11 14:19:22 jaapb Exp $

VERSION=	113.45.68
GITHUB_PROJECT=	ppx_driver
GITHUB_TAG=	f77579e
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_driver/
COMMENT=	Feature-full driver for OCaml AST transformers
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-f77579efe402258608bd8dd7174e71b7333db775
HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none
OCAML_USE_OASIS_DYNRUN=	yes

post-extract:
	${MV} ${WRKSRC}/META.ab ${WRKSRC}/src

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-ppx_optcomp/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
