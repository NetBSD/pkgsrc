# $NetBSD: Makefile,v 1.10 1999/10/27 17:14:09 agc Exp $

DISTNAME=		clispsrc
PKGNAME=		clisp-19990722
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp2.cons.org/pub/lisp/clisp/source/ \
			ftp://ftp.tu-darmstadt.de/pub/programming/languages/lisp/clisp/source/

MAINTAINER=		mjl@emsi.priv.at
HOMEPAGE=		http://clisp.cons.org/~haible/clisp.html

BROKEN=			Bad patch

NOT_FOR_PLATFORM=	*-*-alpha	# severe LP64 problems

MIRROR_DISTFILE=	no

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
WRKSRC=			${WRKDIR}/clisp-1999-07-22/src

do-configure:
	cd ${WRKSRC}; \
	(cd ..;./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}); \
	./makemake --prefix=${LOCALBASE} --with-readline --with-gettext \
	  --with-dynamic-ffi >Makefile

.include "../../mk/bsd.pkg.mk"
