# $NetBSD: Makefile,v 1.15 2000/06/16 23:53:43 wiz Exp $

DISTNAME=		clisp-2000-03-06
PKGNAME=		clisp-20000306
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp2.cons.org/pub/lisp/clisp/source/ \
			ftp://ftp.tu-darmstadt.de/pub/programming/languages/lisp/clisp/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		mjl@netbsd.org
HOMEPAGE=		http://clisp.cons.org/

NOT_FOR_PLATFORM=	*-*-alpha	# severe LP64 problems

MIRROR_DISTFILE=	no

GNU_CONFIGURE=		YES
WRKSRC=			${WRKDIR}/${DISTNAME}/src

do-configure:
	cd ${WRKSRC}; \
	(cd ..;${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}); \
	./makemake --prefix=${LOCALBASE} --with-readline --with-gettext \
	  --with-dynamic-ffi --fsstnd=netbsd >Makefile

post-install:
	${CHOWN} -R root:wheel ${PREFIX}/lib/clisp
	${CHMOD} -R a-w ${PREFIX}/lib/clisp

.include "../../mk/bsd.pkg.mk"
