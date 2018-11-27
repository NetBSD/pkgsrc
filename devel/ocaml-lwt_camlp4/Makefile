# $NetBSD: Makefile,v 1.4 2018/11/27 23:04:03 jaapb Exp $

GITHUB_PROJECT=	lwt_camlp4
GITHUB_TAG=	45f25a0
DISTNAME=	lwt_camlp4-20180325
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=aantron/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/aantron/lwt_camlp4/
COMMENT=	Camlp4 module for ocaml-lwt
LICENSE=	gnu-lgpl-v2.1

CONFLICTS=	ocaml-lwt<3.0.0

WRKSRC=	${WRKDIR}/${GITHUB_PROJECT}-45f25a081e01071ab566924b48ba5f7553bb33ac

OCAML_USE_DUNE=	yes
DUNE_BUILD_PACKAGES=	lwt_camlp4

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
