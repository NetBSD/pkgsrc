# $NetBSD: Makefile,v 1.21 2001/12/05 15:00:46 agc Exp $

DISTNAME=		clisp-2000-03-06
PKGNAME=		clisp-20000306
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp2.cons.org/pub/lisp/clisp/source/ \
			ftp://ftp.tu-darmstadt.de/pub/programming/languages/lisp/clisp/source/
EXTRACT_SUFX=		.tar.bz2

PATCHFILES=		clisp-2000-03-06-bugfix1.diff
PATCH_SITES=		${MASTER_SITES}
PATCH_DIST_STRIP=	-p2

MAINTAINER=		mjl@netbsd.org
HOMEPAGE=		http://clisp.cons.org/
COMMENT=		CLISP, a Common Lisp implementation

NOT_FOR_PLATFORM=	*-*-alpha	# severe LP64 problems

RESTRICTED=		"Contract notify author when selling for profit."
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

GNU_CONFIGURE=		YES
WRKSRC=			${WRKDIR}/${DISTNAME}/src

do-configure:
	cd ${WRKSRC}; \
	(cd ..;${CONFIGURE_SCRIPT} --host=${MACHINE_GNU_PLATFORM} --prefix=${PREFIX}); \
	./makemake --prefix=${LOCALBASE} --with-readline --with-gettext \
	  --with-dynamic-ffi --fsstnd=netbsd >Makefile

post-install:
	${CHOWN} -R ${ROOT_USER}:${ROOT_GROUP} ${PREFIX}/lib/clisp
	${CHMOD} -R a-w ${PREFIX}/lib/clisp

.include "../../mk/bsd.pkg.mk"
