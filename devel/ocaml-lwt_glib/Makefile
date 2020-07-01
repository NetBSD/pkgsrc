# $NetBSD: Makefile,v 1.10 2020/07/01 07:55:46 yyamano Exp $

GITHUB_PROJECT=	lwt_glib
GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-1.1.1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/lwt_glib/
COMMENT=	SSL module for ocaml-lwt
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

CONFLICTS=	ocaml-lwt<3.0.0

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	lwt_glib

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
