# $NetBSD: Makefile,v 1.5 2016/08/18 10:48:06 jaapb Exp $

VERSION=	114.01+04
GITHUB_PROJECT=	ppx_core
GITHUB_TAG=	e5577ab
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_core/
COMMENT=	Standard library for OCaml ppx rewriters
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-e5577ab345e2485cb6a7427f24b35840f5886490

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none
OCAML_USE_OASIS_DYNRUN=	yes

post-extract:
	${MV} ${WRKSRC}/META.ab ${WRKSRC}/src

.include "../../devel/ocaml-js-build-tools/buildlink3.mk"
.include "../../devel/ocaml-oasis/buildlink3.mk"
.include "../../devel/ocaml-ppx_tools/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
