# $NetBSD: Makefile,v 1.2 2018/01/10 16:53:09 jaapb Exp $

PKGREVISION= 1
.include "../../devel/ocaml-lwt/Makefile.common"

PKGNAME=	ocaml-lwt_ssl-1.1.0
CATEGORIES=	devel

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/lwt/
COMMENT=	SSL module for ocaml-lwt

CONFLICTS=	ocaml-lwt<3.0.0

JBUILDER_BUILD_TARGETS=	lwt_ssl

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../security/ocaml-ssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
