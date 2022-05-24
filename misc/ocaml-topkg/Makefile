# $NetBSD: Makefile,v 1.13 2022/05/24 18:51:54 jaapb Exp $

DISTNAME=	topkg-1.0.5
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://erratique.ch/software/topkg/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://erratique.ch/software/topkg/
COMMENT=	Transitory OCaml software packager
LICENSE=	isc

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=		yes

INSTALLATION_DIRS+=	share/doc/topkg

.include "../../lang/ocaml/ocaml.mk"

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
