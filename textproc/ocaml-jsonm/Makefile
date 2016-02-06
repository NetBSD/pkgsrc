# $NetBSD: Makefile,v 1.3 2016/02/06 14:18:34 jaapb Exp $

DISTNAME=	jsonm-0.9.1
PKGNAME=	ocaml-${DISTNAME}
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
