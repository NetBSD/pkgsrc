# $NetBSD: Makefile,v 1.19 2019/11/03 11:45:45 rillig Exp $

GITHUB_PROJECT=	ocaml-ipaddr
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-3.1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-ipaddr/
COMMENT=	Library for manipulation of IP and MAC addresses
LICENSE=	isc

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	macaddr ipaddr
OPAM_INSTALL_FILES=	macaddr ipaddr

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocaml-sexplib0/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_conv/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
