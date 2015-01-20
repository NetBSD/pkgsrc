# $NetBSD: Makefile,v 1.1 2015/01/20 16:27:02 jaapb Exp $

DISTNAME=	sexplib-${VERS}
VERS=		112.01.00
CATEGORIES=	devel
MASTER_SITES=	https://github.com/janestreet/sexplib/archive/
DISTFILES=	${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=	ocaml-sexplib

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/sexplib/
COMMENT=	S-Expressions with Type Converters for OCaml
LICENSE=	modified-bsd AND apache-2.0

OCAML_USE_OASIS=	yes

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
