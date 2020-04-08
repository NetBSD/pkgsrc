# $NetBSD: Makefile,v 1.20 2020/04/08 12:31:01 jaapb Exp $

GITHUB_PROJECT=	ocaml-ipaddr
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-4.0.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-ipaddr/
COMMENT=	Library for manipulation of IP and MAC addresses
LICENSE=	isc

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	macaddr macaddr-cstruct macaddr-sexp \
			ipaddr ipaddr-cstruct ipaddr-sexp
OPAM_INSTALL_FILES=	${DUNE_BUILD_PACKAGES}

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocaml-cstruct/buildlink3.mk"
.include "../../devel/ocaml-sexplib0/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_conv/buildlink3.mk"
.include "../../net/ocaml-domain-name/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
