# $NetBSD: Makefile,v 1.15 2026/03/01 12:38:26 gdt Exp $

PKGREVISION= 2
.include "../../devel/ocaml-lwt/Makefile.common"

PKGNAME=	ocaml-lwt_react-1.1.5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/lwt/
COMMENT=	Reactive programming module for ocaml-lwt

CONFLICTS=	ocaml-lwt<3.0.0

DUNE_BUILD_PACKAGES=	lwt_react

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/ocaml-react/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
