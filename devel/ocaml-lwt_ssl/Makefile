# $NetBSD: Makefile,v 1.16 2026/02/17 13:39:01 wiz Exp $

GITHUB_PROJECT=	lwt_ssl
GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	lwt_ssl-1.1.3
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel security
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/lwt_ssl/
COMMENT=	SSL module for ocaml-lwt
LICENSE=	gnu-lgpl-v2.1

CONFLICTS=	ocaml-lwt<3.0.0

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	lwt_ssl

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../security/ocaml-ssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
