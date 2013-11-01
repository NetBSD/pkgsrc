# $NetBSD: Makefile,v 1.9 2013/11/01 11:30:21 jaapb Exp $
#

DISTNAME=	menhir-20120123
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://cristal.inria.fr/~fpottier/menhir/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://cristal.inria.fr/~fpottier/menhir/
COMMENT=	LR(1) parser generator in OCaml
LICENSE=	qpl-v1.0

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake

BUILD_DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
MAKE_ENV=		EGDIR=${EGDIR:Q}

PLIST_VARS=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64") || \
    (${MACHINE_ARCH} == "arm")
PLIST.opt=	yes
.else
MAKE_ENV+=	TARGET=byte
.endif

INSTALLATION_DIRS=	lib/ocaml/site-lib/menhirLib

post-extract:
	${RM} ${WRKSRC}/demos/calc/.omakedb*

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
