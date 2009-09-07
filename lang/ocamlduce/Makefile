# $NetBSD: Makefile,v 1.5 2009/09/07 21:53:30 tonio Exp $
#

DISTNAME=       ocamlduce-3.11.1.0
CATEGORIES=     lang
MASTER_SITES=   http://forge.ocamlcore.org/frs/download.php/225/
DISTFILES=      ${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

# we need the OCaml sources too
DISTFILES+=	ocaml-3.11.1.tar.bz2
SITES.ocaml-3.11.1.tar.bz2= http://caml.inria.fr/pub/distrib/ocaml-3.11/	

MAINTAINER=     jaapb@kerguelen.org
HOMEPAGE=       http://ocamlduce.ocamlcore.org/
COMMENT=        Library to integrate XML features into OCaml

DEPENDS+=       ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

USE_TOOLS+=     gmake
BUILD_TARGET=   all
INSTALL_TARGET=	installbyte
MAKE_JOBS_SAFE=	no

MAKE_ENV=	BINDIR=${PREFIX}/bin LIBDIR=${PREFIX}/lib/ocaml/site-lib
PLIST_SRC=	PLIST

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
BUILD_TARGET=   world.opt
INSTALL_TARGET+=        installopt
PLIST_SRC+=     PLIST.opt
.else
BUILD_TARGET=   world
.endif

BUILDLINK_API_DEPENDS.ocaml+=   ocaml>=3.11.1
pre-configure:
	cd ${WRKSRC} && DISTDIR=${DISTDIR} make prepare
	cd ${WRKSRC}/ocaml-3.11.1 && ./configure -prefix ${PREFIX} -libs ${LDFLAGS:Q} -with-pthread -host ${MACHINE_GNU_PLATFORM:Q} -mandir ${PREFIX}/${PKGMANDIR} -no-tk

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
