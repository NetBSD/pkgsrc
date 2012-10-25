# $NetBSD: Makefile,v 1.20 2012/10/25 06:55:53 asau Exp $

DISTNAME=	hevea-1.10
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/moscova/hevea/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://pauillac.inria.fr/~maranget/hevea/
COMMENT=	LaTeX to HTML translator

BUILD_DEPENDS+=	ocaml>=3.07:../../lang/ocaml
MAKE_ENV+=	DESTDIR=${DESTDIR}

DIST_SUBDIR=	${PKGNAME_NOREV}
.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
MAKE_ENV+=	TARGET=opt
.else
MAKE_ENV+=	TARGET=byte
.endif

.include "../../mk/bsd.pkg.mk"
