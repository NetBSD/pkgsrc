# $NetBSD: Makefile,v 1.2 2009/06/30 00:07:13 joerg Exp $
#

DISTNAME=	lwt-1.1.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.ocsigen.org/download/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://www.ocsigen.org/
COMMENT=	Cooperative threading library for OCaml

MAKE_JOBS_SAFE=		no

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

BUILD_TARGET=	META byte
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
BUILD_TARGET+=	opt
PLIST_SRC+=	PLIST.opt
.endif

BUILD_TARGET+=	doc
PLIST_SRC+=	PLIST

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/_build/lwt.docdir/* ${PREFIX}/share/doc/${PKGBASE}

.include "../../security/ocaml-ssl/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
