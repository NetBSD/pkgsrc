# $NetBSD: Makefile,v 1.1 1998/09/06 20:45:35 tron Exp $

DISTNAME=	clispsrc-1998-08-29
PKGNAME=	clisp-19980829
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp2.cons.org/pub/lisp/clisp/snapshots/

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
