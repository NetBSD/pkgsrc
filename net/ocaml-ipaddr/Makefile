# $NetBSD: Makefile,v 1.13 2018/04/09 10:24:20 jaapb Exp $

VERSION=	2.8.0
GITHUB_PROJECT=	ocaml-ipaddr
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-ipaddr/
COMMENT=	Library for manipulation of IP and MAC addresses
LICENSE=	isc

OCAML_USE_JBUILDER=	yes

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_conv/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
