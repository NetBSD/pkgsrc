# $NetBSD: Makefile,v 1.1 2013/07/03 10:40:33 jaapb Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	batteries-2.0
CATEGORIES=	devel
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1096/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://batteries.forge.ocamlcore.org/
COMMENT=	Alternative standard library for OCaml
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake

PLIST_VARS=     opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST.opt=              yes
.endif

.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
