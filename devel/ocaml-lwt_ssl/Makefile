# $NetBSD: Makefile,v 1.6 2018/11/12 16:10:16 jaapb Exp $

PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
DISTNAME=	lwt_ssl-1.1.2
CATEGORIES=	devel security
GITHUB_PROJECT=	lwt_ssl
GITHUB_TAG=	${PKGVERSION_NOREV}

MASTER_SITES=	${MASTER_SITE_GITHUB:=aantron/}
LICENSE=	gnu-lgpl-v2.1

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/aantron/lwt_ssl/
COMMENT=	SSL module for ocaml-lwt

CONFLICTS=	ocaml-lwt<3.0.0

OCAML_USE_JBUILDER=	yes
JBUILDER_BUILD_PACKAGES=	lwt_ssl

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../security/ocaml-ssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
