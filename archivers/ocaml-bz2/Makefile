# $NetBSD: Makefile,v 1.2 2012/10/02 23:47:56 asau Exp $

PKGNAME=	ocaml-bz2-${VERSION}
DISTNAME=	camlbz2-${VERSION}
VERSION=	0.6.0
CATEGORIES=	archivers
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/72/

MAINTAINER=	jaapb@NetBSD.org
COMMENT=	OCaml library to manipulate bz2 archives
HOMEPAGE=	http://camlbz2.forge.ocamlcore.org/
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_JOBS_SAFE=	no

PLIST_VARS+=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64") || \
    (${MACHINE_ARCH} == "arm")
PLIST.opt=	yes
.endif

.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
