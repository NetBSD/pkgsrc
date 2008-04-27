# $NetBSD: Makefile,v 1.3 2008/04/27 10:44:28 tonio Exp $
#

DISTNAME=	camlp5-5.08
CATEGORIES=	lang
MASTER_SITES=	http://pauillac.inria.fr/~ddr/camlp5/distrib/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://pauillac.inria.fr/~ddr/camlp5/
COMMENT=	Camlp5 is a preprocessor-pretty-printer of ocaml

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c # needed for optimised compiler

CONFIGURE_ARGS+=	--bindir ${PREFIX}/bin
CONFIGURE_ARGS+=	--mandir ${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--libdir ${PREFIX}/lib/ocaml

REPLACE_SH=	tools/*.sh meta/*.sh ocaml_src/tools/*.sh compile/*.sh

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
BUILD_TARGET=	world.opt
PLIST_SRC+=	${PKGDIR}/PLIST.opt
.else
BUILD_TARGET=	world
.endif
PLIST_SRC+=	${PKGDIR}/PLIST

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
