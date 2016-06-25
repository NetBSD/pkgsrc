# $NetBSD: Makefile,v 1.15 2016/06/25 14:01:34 jaapb Exp $
#

PKGNAME=	ocaml-zip-${VERSION}
DISTNAME=	camlzip-${VERSION}
VERSION=	1.06
CATEGORIES=	archivers
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1616/
LICENSE=	gnu-lgpl-v2.1

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://forge.ocamlcore.org/projects/camlzip/
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
