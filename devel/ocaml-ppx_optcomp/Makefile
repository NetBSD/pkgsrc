# $NetBSD: Makefile,v 1.7 2017/07/11 14:15:50 jaapb Exp $

VERSION=	114.08.89
PKGREVISION=	2
GITHUB_PROJECT=	ppx_optcomp
GITHUB_TAG=	6f1ce80
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_optcomp/
COMMENT=	Optional compilation for OCaml
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-6f1ce80b1e9dff9b02a1579209e9655994151e15
HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none
OCAML_USE_OASIS_DYNRUN=	yes
CONFIGURE_ARGS+=	--bindir ${DESTDIR}${PREFIX}/bin

post-extract:
	${MV} ${WRKSRC}/META.ab ${WRKSRC}/src

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-ppx_core/buildlink3.mk"
.include "../../devel/ocaml-ppx_deriving/buildlink3.mk"
.include "../../devel/ocaml-ppx_tools/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
