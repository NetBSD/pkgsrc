# $NetBSD: Makefile,v 1.7 2018/11/27 15:27:18 jaapb Exp $

GITHUB_PROJECT=	configurator
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.11.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/configurator/
COMMENT=	Helper library for gathering system configuration
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake
OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-stdio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
