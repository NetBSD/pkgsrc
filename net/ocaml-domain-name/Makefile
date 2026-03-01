# $NetBSD: Makefile,v 1.7 2026/03/01 12:38:37 gdt Exp $

DISTNAME=	ocaml-${GITHUB_PROJECT}-0.4.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hannesm/}
GITHUB_PROJECT=	domain-name
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hannesm/domain-name/
COMMENT=	RFC 1035 Internet domain name library for OCaml
LICENSE=	isc

OCAML_USE_DUNE=		yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
