# $NetBSD: Makefile,v 1.11 2026/02/17 13:39:00 wiz Exp $

DISTNAME=	lwt_log-1.1.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel security
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}
GITHUB_PROJECT=	lwt_log
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/lwt_log/
COMMENT=	Lwt-friendly logging library
LICENSE=	gnu-lgpl-v2.1

CONFLICTS=	ocaml-lwt<3.0.0

OCAML_USE_DUNE=	yes
JBUILDER_BUILD_PACKAGES=	lwt_log

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
