# $NetBSD: Makefile,v 1.14 2000/06/01 11:23:33 rh Exp $

DISTNAME=		clisp-2000-03-06
PKGNAME=		clisp-20000306
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp2.cons.org/pub/lisp/clisp/source/ \
			ftp://ftp.tu-darmstadt.de/pub/programming/languages/lisp/clisp/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		mjl@netbsd.org
HOMEPAGE=		http://clisp.cons.org/~haible/clisp.html

NOT_FOR_PLATFORM=	*-*-alpha	# severe LP64 problems

MIRROR_DISTFILE=	no

GNU_CONFIGURE=		YES
WRKSRC=			${WRKDIR}/${DISTNAME}/src
# USE_PKGLIBTOOL=		YES

do-configure:
	cd ${WRKSRC}; \
	(cd ..;${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}); \
	./makemake --prefix=${LOCALBASE} --with-readline --with-gettext \
	  --with-dynamic-ffi >Makefile

post-install:
	${CHOWN} -R root:wheel ${PREFIX}/lib/clisp
	${CHMOD} -R a-w ${PREFIX}/lib/clisp

.include "../../mk/bsd.pkg.mk"
