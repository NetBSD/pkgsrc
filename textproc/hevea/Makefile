# $NetBSD: Makefile,v 1.21 2015/05/06 20:45:43 tonio Exp $

DISTNAME=	hevea-2.23
CATEGORIES=	textproc
MASTER_SITES=	http://hevea.inria.fr/distri/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://hevea.inria.fr/
COMMENT=	LaTeX to HTML translator
LICENSE=	qpl-v1.0

MAKE_ENV+=	DESTDIR=${DESTDIR}

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
BUILD_DEPENDS+=	ocaml>=3.12:../../lang/ocaml
MAKE_ENV+=	TARGET=opt
.else
DEPENDS+=	ocaml>=3.12:../../lang/ocaml
MAKE_ENV+=	TARGET=byte
.endif

.include "../../mk/bsd.pkg.mk"
