# $NetBSD: Makefile,v 1.1.1.1 2012/06/04 13:13:14 wiz Exp $
#

DISTNAME=	tyxml-2.1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://ocsigen.org/download/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://ocsigen.org/download/
COMMENT=	OCaml XML typing library
LICENSE=	gnu-lgpl-v2.1 # with openssl exemption

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
USE_TOOLS=	gmake

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
CONFLICTS+=	ocsigen<2.0

MAKE_ENV+=	INSTALLDIR="${DESTDIR}${PREFIX}/lib/ocaml/site-lib"

PLIST_VARS=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST.opt=	yes
.endif

pre-install:
	${RM} -rf ${DESTDIR}${PREFIX}/lib/ocaml/site-lib/tyxml
	${MKDIR} ${DESTDIR}${PREFIX}/lib/ocaml/site-lib

.include "../../net/ocamlnet/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
