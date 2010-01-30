# $NetBSD: Makefile,v 1.2 2010/01/30 17:43:42 joerg Exp $
#

DISTNAME=	camlzip-${VERSION}
PKGNAME=	ocaml-zip-${VERSION}
VERSION=	1.03
CATEGORIES=	archivers
MASTER_SITES=	http://caml.inria.fr/distrib/bazar-ocaml/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://cristal.inria.fr/~xleroy/software.html
COMMENT=	OCaml library to manipulate ZIP/GZIP/JAR archives

PKG_DESTDIR_SUPPORT=	user-destdir

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
