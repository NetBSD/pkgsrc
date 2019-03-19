# $NetBSD: Makefile,v 1.1 2019/03/19 11:25:41 jaapb Exp $

DISTNAME=	logs-0.6.2
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/logs/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://erratique.ch/software/logs/
COMMENT=	Logging infrastructure for OCaml
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=	yes

.include "options.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
