# $NetBSD: Makefile,v 1.11 2026/10/20 21:40:39 alnsn Exp $

DISTNAME=	logs-0.7.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	6
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
