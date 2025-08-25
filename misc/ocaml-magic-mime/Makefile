# $NetBSD: Makefile,v 1.6 2025/08/25 08:35:09 wiz Exp $

GITHUB_PROJECT=	ocaml-magic-mime
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-1.2.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-magic-mime/
COMMENT=	Convert file extensions to MIME types
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
