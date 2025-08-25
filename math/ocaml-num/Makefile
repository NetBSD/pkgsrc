# $NetBSD: Makefile,v 1.9 2025/08/25 08:35:08 wiz Exp $

GITHUB_PROJECT=	num
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-1.4
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/num/
COMMENT=	Library for arbitrary-precision arithmetic
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

BUILD_TARGET=		all
INSTALLATION_DIRS+=	lib/ocaml/stublibs

OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_DIRS+=	num-top

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
