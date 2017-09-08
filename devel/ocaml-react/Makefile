# $NetBSD: Makefile,v 1.15 2017/09/08 09:51:22 jaapb Exp $

DISTNAME=	react-1.2.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://erratique.ch/software/react/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://erratique.ch/software/react
COMMENT=	OCaml module for functional reactive programming
LICENSE=	isc

CONFIGURE_ARGS+=	--prefix "${PREFIX}" --destdir "${DESTDIR}"
INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}/react

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=		yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
