# $NetBSD: Makefile,v 1.2 2026/02/17 13:39:14 wiz Exp $

DISTNAME=	xmlm-1.4.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://erratique.ch/software/xmlm/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://erratique.ch/software/xmlm/
COMMENT=	Streaming codec to decode and encode XML
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=		yes

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
