# $NetBSD: Makefile,v 1.27 2026/03/01 12:38:32 gdt Exp $

DISTNAME=	react-1.2.2
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/react/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://erratique.ch/software/react
COMMENT=	OCaml module for functional reactive programming
LICENSE=	isc

CONFIGURE_ARGS+=	--prefix "${PREFIX}" --destdir "${DESTDIR}"
INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}/react

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=		yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
