# $NetBSD: Makefile,v 1.6 1999/01/31 23:37:28 tron Exp $

DISTNAME=	clispsrc-19990108
PKGNAME=	clisp-19990108
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	mjl@emsi.priv.at
HOMEPAGE=	http://clisp.cons.org/~haible/clisp.html

CONFLICTS=	clisp-*

NOT_FOR_ARCHS=	alpha	# severe LP64 problems

MIRROR_DISTFILE=	no

GCC_VERSION!=	gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs) && !target(clean)
IGNORE=		"cannot be built with egcs yet"
.endif

GNU_CONFIGURE=		YES
WRKSRC=			${WRKDIR}/clisp-1999-01-08/src

do-configure:
	cd ${WRKSRC}; \
	(cd ..;./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}); \
	./makemake --prefix=${LOCALBASE} --with-readline --with-gettext \
	  --with-dynamic-ffi >Makefile

.include "../../mk/bsd.pkg.mk"
