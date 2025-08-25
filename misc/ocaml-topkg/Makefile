# $NetBSD: Makefile,v 1.15 2025/08/25 08:35:09 wiz Exp $

DISTNAME=	topkg-1.0.7
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	http://erratique.ch/software/topkg/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://erratique.ch/software/topkg/
COMMENT=	Transitory OCaml software packager
LICENSE=	isc

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=		yes

INSTALLATION_DIRS+=	share/doc/topkg

.include "../../lang/ocaml/ocaml.mk"

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
