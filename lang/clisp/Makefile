# $NetBSD: Makefile,v 1.2 1998/09/22 06:11:37 garbled Exp $

DISTNAME=	clispsrc-1998-08-29
PKGNAME=	clisp-19980829
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp2.cons.org/pub/lisp/clisp/snapshots/

NOT_FOR_ARCHS=	alpha	# severe LP64 problems

MAINTAINER=	mjl@emsi.priv.at
HOMEPAGE=	http://clisp.cons.org/~haible/clisp.html

GNU_CONFIGURE=	YES
WRKSRC=		${WRKDIR}/clisp-1998-08-29

post-configure:
	( cd ${WRKSRC}/src; \
	./makemake --prefix=${LOCALBASE} --with-readline --with-gettext --with-dynamic-ffi > Makefile )

do-build:
	( cd ${WRKSRC}/src; ${MAKE_PROGRAM} )

do-install:
	( cd ${WRKSRC}/src; ${MAKE_PROGRAM} install )

.include "../../mk/bsd.pkg.mk"
