# $NetBSD: Makefile,v 1.25 2026/02/17 13:39:11 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-5.3.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_PROJECT=	ocaml-ipaddr
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-ipaddr/
COMMENT=	Library for manipulation of IP and MAC addresses
LICENSE=	isc

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	macaddr macaddr-cstruct macaddr-sexp \
			ipaddr ipaddr-cstruct ipaddr-sexp
OPAM_INSTALL_FILES=	${DUNE_BUILD_PACKAGES}
OCAML_FINDLIB_DIRS=	${DUNE_BUILD_PACKAGES}

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocaml-cstruct/buildlink3.mk"
.include "../../devel/ocaml-sexplib0/buildlink3.mk"
.include "../../devel/ocaml-stdlib-shims/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_conv/buildlink3.mk"
.include "../../net/ocaml-domain-name/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
