# $NetBSD: Makefile,v 1.3 1998/11/13 01:15:16 frueauf Exp $

DISTNAME=	clispsrc-1998-08-29
PKGNAME=	clisp-19980829
WRKSRC=		${WRKDIR}/clisp-1998-08-29
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp2.cons.org/pub/lisp/clisp/snapshots/

MAINTAINER=	mjl@emsi.priv.at
HOMEPAGE=	http://clisp.cons.org/~haible/clisp.html

NOT_FOR_ARCHS=	alpha	# severe LP64 problems

GNU_CONFIGURE=	YES

post-configure:
	( cd ${WRKSRC}/src; \
	./makemake --prefix=${LOCALBASE} --with-readline --with-gettext --with-dynamic-ffi > Makefile )

do-build:
	( cd ${WRKSRC}/src; ${MAKE_PROGRAM} )

do-install:
	( cd ${WRKSRC}/src; ${MAKE_PROGRAM} install )

.include "../../mk/bsd.pkg.mk"
