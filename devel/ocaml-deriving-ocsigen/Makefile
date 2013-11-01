# $NetBSD: Makefile,v 1.4 2013/11/01 11:42:40 jaapb Exp $
#

DISTNAME=	deriving-ocsigen-0.5
PKGNAME=	ocaml-${DISTNAME}
COMMENT=	Extension to OCaml for deriving functions from type declarations
CATEGORIES=	devel
MASTER_SITES=	http://ocsigen.org/download/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://ocsigen.org/eliom/install/
LICENSE=	mit

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

USE_LANGUAGES=	c
USE_TOOLS=	gmake

INSTALLATION_DIRS= lib/ocaml/site-lib

PLIST_VARS=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST.opt=	yes
.endif


.include "../../devel/ocaml-optcomp/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
