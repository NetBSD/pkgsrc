# $NetBSD: Makefile,v 1.24 2018/11/12 16:10:17 jaapb Exp $
#

VERSION=	1.07
GITHUB_PROJECT=	camlzip
GITHUB_TAG=	rel${VERSION:S/.//}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-zip-${VERSION}
PKGREVISION=	5
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=xavierleroy/}
LICENSE=	gnu-lgpl-v2.1

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/xavierleroy/camlzip
COMMENT=	OCaml library to manipulate ZIP/GZIP/JAR archives

BUILD_TARGET=	all
INSTALL_TARGET=	install-findlib
USE_TOOLS+=	gmake
OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET+=	allopt
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
