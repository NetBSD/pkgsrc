# $NetBSD: Makefile,v 1.4 2021/03/28 12:30:19 mef Exp $

DISTNAME=	fpath-0.7.2
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/fpath/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://erratique.ch/software/fpath/
COMMENT=	System-independent file path for OCaml
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=		yes

.include "../../devel/ocaml-astring/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
