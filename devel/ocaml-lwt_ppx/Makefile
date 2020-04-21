# $NetBSD: Makefile,v 1.8 2020/04/21 11:31:19 jaapb Exp $

.include "../../devel/ocaml-lwt/Makefile.common"

PKGNAME=	ocaml-lwt_ppx-2.0.1
CATEGORIES=	devel

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/lwt/
COMMENT=	PPX module for ocaml-lwt

CONFLICTS=	ocaml-lwt<3.0.0

DUNE_BUILD_PACKAGES=	lwt_ppx

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
