# $NetBSD: Makefile,v 1.1 2018/04/09 08:58:47 jaapb Exp $

.include "../../devel/ocaml-lwt/Makefile.common"

PKGNAME=	ocaml-lwt_ppx-1.1.0
CATEGORIES=	devel

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/lwt/
COMMENT=	PPX module for ocaml-lwt

CONFLICTS=	ocaml-lwt<3.0.0

JBUILDER_BUILD_PACKAGES=	lwt_ppx

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
