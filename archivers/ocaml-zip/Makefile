# $NetBSD: Makefile,v 1.5 2012/09/11 19:46:58 asau Exp $
#

PKGNAME=	ocaml-zip-${VERSION}
DISTNAME=	camlzip-${VERSION}
VERSION=	1.04
CATEGORIES=	archivers
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/328/
LICENSE=	gnu-lgpl-v2.1

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://forge.ocamlcore.org/projects/camlzip/
COMMENT=	OCaml library to manipulate ZIP/GZIP/JAR archives

BUILD_TARGET=	all

PLIST_VARS+=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
BUILD_TARGET+=	allopt
PLIST.opt=	yes
.endif

post-extract:
	${CP} ${FILESDIR}/META ${WRKSRC}/META

.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
