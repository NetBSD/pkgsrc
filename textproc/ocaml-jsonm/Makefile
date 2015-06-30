# $NetBSD: Makefile,v 1.2 2015/06/30 11:52:59 jaapb Exp $

DISTNAME=	jsonm-0.9.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://erratique.ch/software/jsonm/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://erratique.ch/software/jsonm/
COMMENT=	OCaml streaming codec for JSON
LICENSE=	modified-bsd

OCAML_USE_FINDLIB=	yes
OCAML_USE_OASIS=	yes

.include "../../mk/ocaml.mk"
.include "../../textproc/ocaml-uutf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
