# $NetBSD: Makefile,v 1.6 2015/01/20 14:24:37 jaapb Exp $
#

DISTNAME=	ocaml-expat-0.9.1
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://mmzeeman.home.xs4all.nl/ocaml/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://mmzeeman.home.xs4all.nl/ocaml/
COMMENT=	OCaml bindings for the expat library
LICENSE=	mit

USE_TOOLS+=	gmake
USE_LANGUAGES=	c
BUILD_TARGET=	all

PLIST_VARS+=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64") || \
    (${MACHINE_ARCH} == "arm")
PLIST.opt=	yes
BUILD_TARGET+=	allopt expat.cmxs
.endif

.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
