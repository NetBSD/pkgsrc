# $NetBSD: Makefile,v 1.4 2018/11/12 16:10:20 jaapb Exp $

PKGREVISION= 1
.include "../../devel/ocaml-lwt/Makefile.common"

PKGNAME=	ocaml-lwt_ppx-1.2.1
CATEGORIES=	devel

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/lwt/
COMMENT=	PPX module for ocaml-lwt

CONFLICTS=	ocaml-lwt<3.0.0

JBUILDER_BUILD_PACKAGES=	lwt_ppx

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
