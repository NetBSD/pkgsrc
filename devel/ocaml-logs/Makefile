# $NetBSD: Makefile,v 1.7 2022/05/24 18:51:49 jaapb Exp $

DISTNAME=	logs-0.7.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/logs/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://erratique.ch/software/logs/
COMMENT=	Logging infrastructure for OCaml
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=		yes

.include "options.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
