# $NetBSD: Makefile,v 1.10 2022/05/02 14:07:16 jaapb Exp $

.include "../../devel/ocaml-lwt/Makefile.common"

PKGNAME=	ocaml-lwt_ppx-2.0.3
CATEGORIES=	devel

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/lwt/
COMMENT=	PPX module for ocaml-lwt

CONFLICTS=	ocaml-lwt<3.0.0

DUNE_BUILD_PACKAGES=	lwt_ppx

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
