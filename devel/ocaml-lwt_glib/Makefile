# $NetBSD: Makefile,v 1.14 2025/08/25 08:35:00 wiz Exp $

GITHUB_PROJECT=	lwt_glib
GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-1.1.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/lwt_glib/
COMMENT=	SSL module for ocaml-lwt
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

CONFLICTS=	ocaml-lwt<3.0.0

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	lwt_glib

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
