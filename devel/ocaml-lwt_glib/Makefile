# $NetBSD: Makefile,v 1.2 2017/09/12 08:15:06 dholland Exp $

.include "../../devel/ocaml-lwt/Makefile.common"

PKGNAME=	ocaml-lwt_glib-1.1.0
CATEGORIES=	devel

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/lwt/
COMMENT=	Glib module for ocaml-lwt

CONFLICTS=	ocaml-lwt<3.0.0
USE_TOOLS+=	pkg-config

JBUILDER_BUILD_TARGETS=	lwt_glib

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
