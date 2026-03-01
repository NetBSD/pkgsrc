# $NetBSD: Makefile,v 1.3 2026/03/01 12:38:40 gdt Exp $

DISTNAME=	xmlm-1.4.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
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
