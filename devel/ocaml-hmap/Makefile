# $NetBSD: Makefile,v 1.3 2025/08/25 08:34:58 wiz Exp $

DISTNAME=	hmap-0.8.1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/hmap/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://erratique.ch/software/hmap/
COMMENT=	Heterogeneous value map library
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=		yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
