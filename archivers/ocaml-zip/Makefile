# $NetBSD: Makefile,v 1.3 2011/12/06 00:19:22 sbd Exp $
#

DISTNAME=	camlzip-${VERSION}
PKGNAME=	ocaml-zip-${VERSION}
VERSION=	1.03
PKGREVISION=	1
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
