# $NetBSD: Makefile,v 1.9 1999/05/24 20:39:43 tv Exp $

DISTNAME=		clispsrc
PKGNAME=		clisp-19990108
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp2.cons.org/pub/lisp/clisp/source/ \
			ftp://ftp.tu-darmstadt.de/pub/programming/languages/lisp/clisp/source/

MAINTAINER=		mjl@emsi.priv.at
HOMEPAGE=		http://clisp.cons.org/~haible/clisp.html

NOT_FOR_PLATFORM=	*-*-alpha	# severe LP64 problems

MIRROR_DISTFILE=	no

GNU_CONFIGURE=		YES
WRKSRC=			${WRKDIR}/clisp-1999-01-08/src

do-configure:
	cd ${WRKSRC}; \
	(cd ..;./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}); \
	./makemake --prefix=${LOCALBASE} --with-readline --with-gettext \
	  --with-dynamic-ffi >Makefile

.include "../../mk/bsd.pkg.mk"
