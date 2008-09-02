# $NetBSD: Makefile,v 1.1.1.1 2008/09/02 11:45:32 obache Exp $
#

DISTNAME=	camlzip-${VERSION}
PKGNAME=	ocaml-zip-${VERSION}
VERSION=	1.03
CATEGORIES=	archivers
MASTER_SITES=	http://caml.inria.fr/distrib/bazar-ocaml/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://cristal.inria.fr/~xleroy/software.html
COMMENT=	OCaml library to manipulate ZIP/GZIP/JAR archives

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

BUILD_TARGET=	all

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
BUILD_TARGET+=	allopt
PLIST_SRC+=	PLIST.opt
.endif

PLIST_SRC+=	PLIST

post-extract:
	${CP} ${FILESDIR}/META ${WRKSRC}/META

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
