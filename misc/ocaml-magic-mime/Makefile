# $NetBSD: Makefile,v 1.1 2019/07/01 15:53:30 jaapb Exp $

GITHUB_PROJECT=	ocaml-magic-mime
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-1.1.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-magic-mime/
COMMENT=	Convert file extensions to MIME types
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
