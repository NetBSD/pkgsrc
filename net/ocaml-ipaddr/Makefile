# $NetBSD: Makefile,v 1.9 2017/07/11 12:28:51 jaapb Exp $

VERSION=	2.7.2
GITHUB_PROJECT=	ocaml-ipaddr
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-ipaddr/
COMMENT=	Library for manipulation of IP and MAC addresses
LICENSE=	isc

WRKSRC=		${WRKDIR}/ocaml-ipaddr-${VERSION}

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=	yes

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocaml-sexplib/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_conv/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
