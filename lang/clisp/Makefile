# $NetBSD: Makefile,v 1.11 1999/12/18 04:53:17 mjl Exp $

DISTNAME=		clisp-1999-07-22
PKGNAME=		clisp-19990722
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp2.cons.org/pub/lisp/clisp/source/ \
			ftp://ftp.tu-darmstadt.de/pub/programming/languages/lisp/clisp/source/

MAINTAINER=		mjl@netbsd.org
HOMEPAGE=		http://clisp.cons.org/~haible/clisp.html

NOT_FOR_PLATFORM=	*-*-alpha	# severe LP64 problems

MIRROR_DISTFILE=	no

GNU_CONFIGURE=		YES
WRKSRC=			${WRKDIR}/${DISTNAME}/src
# USE_LIBTOOL=		yes

do-configure:
	cd ${WRKSRC}; \
	(cd ..;./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}); \
	./makemake --prefix=${LOCALBASE} --with-readline --with-gettext \
	  --with-dynamic-ffi >Makefile

.include "../../mk/bsd.pkg.mk"
