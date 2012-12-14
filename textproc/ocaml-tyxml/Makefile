# $NetBSD: Makefile,v 1.4 2012/12/14 14:44:53 jaapb Exp $
#

DISTNAME=	tyxml-2.2.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://ocsigen.org/download/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://ocsigen.org/download/
COMMENT=	OCaml XML typing library
LICENSE=	gnu-lgpl-v2.1 # with openssl exemption

USE_LANGUAGES=	c
USE_TOOLS=	gmake

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
CONFLICTS+=	ocsigen<2.0

MAKE_ENV+=	INSTALLDIR="${DESTDIR}${PREFIX}/lib/ocaml/site-lib"
INSTALLATION_DIRS=	lib/ocaml/site-lib

PLIST_VARS=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST.opt=	yes
.endif

.include "../../lang/ocaml/buildlink3.mk"
.include "../../net/ocamlnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
