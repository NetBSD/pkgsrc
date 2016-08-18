# $NetBSD: Makefile,v 1.5 2016/08/18 11:23:48 jaapb Exp $

VERSION=	114.01+04
GITHUB_PROJECT=	ppx_type_conv
GITHUB_TAG=	f481969
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_type_conv/
COMMENT=	Support library for type-driven code generators
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-f4819697dc28759dd9a5b71e876bb6c0cfce0944
HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none
OCAML_USE_OASIS_DYNRUN=	yes

post-extract:
	${MV} ${WRKSRC}/META.ab ${WRKSRC}/src

.include "../../mk/ocaml.mk"
#.include "../../devel/ocaml-oasis/buildlink3.mk"
.include "../../devel/ocaml-ppx_deriving/buildlink3.mk"
.include "../../devel/ocaml-ppx_driver/buildlink3.mk"
.include "../../devel/ocaml-ppx_tools/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
#.include "../../misc/ocaml-opam/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
