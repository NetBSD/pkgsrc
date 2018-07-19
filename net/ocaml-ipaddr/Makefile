# $NetBSD: Makefile,v 1.15 2018/07/19 15:15:27 jaapb Exp $

VERSION=	2.8.0
GITHUB_PROJECT=	ocaml-ipaddr
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGREVISION=	5
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
