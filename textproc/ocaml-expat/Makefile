# $NetBSD: Makefile,v 1.3 2012/12/26 10:27:14 jaapb Exp $
#

DISTNAME=	ocaml-expat-0.9.1
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
BUILD_TARGET+=	allopt
.endif

.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
