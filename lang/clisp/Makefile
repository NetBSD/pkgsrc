# $NetBSD: Makefile,v 1.4 1998/11/22 19:39:48 tron Exp $

DISTNAME=	clispsrc
PKGNAME=	clisp-19980909
WRKSRC=		${WRKDIR}/clisp-1998-09-09
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp2.cons.org/pub/lisp/clisp/source/

MAINTAINER=	mjl@emsi.priv.at
HOMEPAGE=	http://clisp.cons.org/~haible/clisp.html

CONFLICTS=	clisp-19980829

NOT_FOR_ARCHS=	alpha	# severe LP64 problems

GNU_CONFIGURE=		YES
WRKSRC=			${WRKDIR}/clisp-1998-09-09/src

do-configure:
	cd ${WRKSRC}; \
	(cd ..;./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}); \
	./makemake --prefix=${LOCALBASE} --with-readline --with-gettext \
	  --with-dynamic-ffi >Makefile

.include "../../mk/bsd.pkg.mk"
