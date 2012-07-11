# $NetBSD: Makefile,v 1.1 2012/07/11 15:33:51 wiz Exp $
#

DISTNAME=	deriving-ocsigen-0.3c
PKGNAME=	ocaml-${DISTNAME}
COMMENT=	Extension to OCaml for deriving functions from type declarations
CATEGORIES=	devel
MASTER_SITES=	http://ocsigen.org/download/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://ocsigen.org/eliom/install/
LICENSE=	mit

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

PKG_DESTDIR_SUPPORT=	user-destdir

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
