# $NetBSD: Makefile,v 1.1 2020/04/08 12:26:20 jaapb Exp $

GITHUB_PROJECT=	domain-name
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	ocaml-${GITHUB_PROJECT}-0.3.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hannesm/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-ipaddr/
COMMENT=	RFC 1035 Internet domain name library for OCaml
LICENSE=	isc

OCAML_USE_DUNE=		yes

.include "../../devel/ocaml-astring/buildlink3.mk"
.include "../../devel/ocaml-fmt/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
