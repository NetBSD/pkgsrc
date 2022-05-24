# $NetBSD: Makefile,v 1.4 2022/05/24 18:59:34 jaapb Exp $

DISTNAME=	ocaml-${GITHUB_PROJECT}-0.4.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hannesm/}
GITHUB_PROJECT=	domain-name
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/hannesm/domain-name/
COMMENT=	RFC 1035 Internet domain name library for OCaml
LICENSE=	isc

OCAML_USE_DUNE=		yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
