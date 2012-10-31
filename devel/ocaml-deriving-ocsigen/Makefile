# $NetBSD: Makefile,v 1.3 2012/10/31 11:17:33 asau Exp $
#

DISTNAME=	deriving-ocsigen-0.3c
PKGNAME=	ocaml-${DISTNAME}
COMMENT=	Extension to OCaml for deriving functions from type declarations
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://ocsigen.org/download/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://ocsigen.org/eliom/install/
LICENSE=	mit

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

USE_LANGUAGES=	c
USE_TOOLS=	gmake

PLIST_VARS=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST.opt=	yes
.endif

pre-install:
	${MKDIR} ${DESTDIR}${PREFIX}/lib/ocaml/site-lib

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
