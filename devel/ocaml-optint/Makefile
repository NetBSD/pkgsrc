# $NetBSD: Makefile,v 1.2 2020/12/02 08:21:44 he Exp $

GITHUB_PROJECT=	optint
GITHUB_TAG=	v${PKGVERSION_NOREV}
VER=		0.0.4
DISTNAME=	${GITHUB_PROJECT}-${VER}
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/optint/
COMMENT=	Library to provide fast integer (x64) or allocated int32 (x84)
LICENSE=	mit

OCAML_USE_DUNE=	yes

WRKSRC=		${WRKDIR}/optint-${VER}
USE_LANGUAGES=	# none

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
