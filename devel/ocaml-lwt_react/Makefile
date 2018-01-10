# $NetBSD: Makefile,v 1.2 2018/01/10 16:53:09 jaapb Exp $

PKGREVISION= 1
.include "../../devel/ocaml-lwt/Makefile.common"

PKGNAME=	ocaml-lwt_react-1.1.0
CATEGORIES=	devel

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/lwt/
COMMENT=	Reactive programming module for ocaml-lwt

CONFLICTS=	ocaml-lwt<3.0.0

JBUILDER_BUILD_TARGETS=	lwt_react

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/ocaml-react/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
