# $NetBSD: Makefile,v 1.7 2018/11/27 16:43:05 jaapb Exp $

DISTNAME=	topkg-1.0.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	http://erratique.ch/software/topkg/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://erratique.ch/software/topkg/
COMMENT=	Transitory OCaml software packager
LICENSE=	isc

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=	yes

INSTALLATION_DIRS+=	share/doc/topkg

.include "../../mk/ocaml.mk"

.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
