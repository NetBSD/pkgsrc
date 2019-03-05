# $NetBSD: Makefile,v 1.5 2019/03/05 17:16:32 jaapb Exp $

DISTNAME=	lwt_log-1.1.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel security
MASTER_SITES=	${MASTER_SITE_GITHUB:=aantron/}
GITHUB_PROJECT=	lwt_log
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/aantron/lwt_log/
COMMENT=	Lwt-friendly logging library
LICENSE=	gnu-lgpl-v2.1

CONFLICTS=	ocaml-lwt<3.0.0

OCAML_USE_DUNE=	yes
JBUILDER_BUILD_PACKAGES=	lwt_log

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
