# $NetBSD: Makefile,v 1.6 2016/05/05 11:45:39 jaapb Exp $

DISTNAME=	sexplib-${VERS}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
VERS=		113.24.00
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/sexplib/archive/}
DISTFILES=	${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=	ocaml-sexplib

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/sexplib/
COMMENT=	S-Expressions with Type Converters for OCaml
LICENSE=	modified-bsd AND apache-2.0

OCAML_USE_OASIS_DYNRUN=	yes

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
