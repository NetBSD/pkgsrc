# $NetBSD: Makefile,v 1.30 2026/02/17 13:38:53 wiz Exp $
#

VERSION=	1.11
GITHUB_PROJECT=	camlzip
GITHUB_TAG=	rel${VERSION:S/.//}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-zip-${VERSION}
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=xavierleroy/}
LICENSE=	gnu-lgpl-v2.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xavierleroy/camlzip
COMMENT=	OCaml library to manipulate ZIP/GZIP/JAR archives

BUILD_TARGET=		all
INSTALL_TARGET=		install-findlib
USE_TOOLS+=		gmake
OCAML_USE_FINDLIB=	yes

.include "../../lang/ocaml/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET+=	allopt
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
