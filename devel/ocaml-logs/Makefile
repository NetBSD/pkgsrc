# $NetBSD: Makefile,v 1.10 2026/03/01 12:38:25 gdt Exp $

DISTNAME=	logs-0.7.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/logs/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
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
