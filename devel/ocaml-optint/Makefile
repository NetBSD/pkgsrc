# $NetBSD: Makefile,v 1.1 2019/03/12 17:47:09 jaapb Exp $

GITHUB_PROJECT=	optint
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.0.2
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/optint/
COMMENT=	Library to provide fast integer (x64) or allocated int32 (x84)
LICENSE=	mit

OCAML_USE_DUNE=	yes

WRKSRC=		${WRKDIR}/optint-0.0.2
USE_LANGUAGES=	# none

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
