# $NetBSD: Makefile,v 1.2 2005/06/17 04:49:47 jlam Exp $

DISTNAME=	se
PKGNAME=	SmartEiffel-2.0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.loria.fr/pub/loria/SmartEiffel/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	lars.nordlund@hem.utfors.se
HOMEPAGE=	http://smarteiffel.loria.fr/
COMMENT=	The GNU Eiffel Compiler

WRKSRC=		${WRKDIR}/SmartEiffel

DIST_SUBDIR=	${PKGNAME_NOREV}

MAKE_ENV=	SmartEiffel=${WRKSRC}/sys/system.se

# This package relies heavily on GCC.
ONLY_FOR_COMPILER=	gcc

post-patch:
	${SED} "s:XXXWORKDIRXXX:${WRKDIR}:g" ${FILESDIR}/system.se \
		> ${WRKSRC}/sys/system.se

post-build:
	${MV} -f ${WRKSRC}/sys/system.se ${WRKSRC}/sys/system.se.bak
	${SED} "s:${WRKDIR}:${LOCALBASE}:g" ${WRKSRC}/sys/system.se.bak > \
		${WRKSRC}/sys/system.se
	${RM} -f ${WRKSRC}/sys/system.se.bak
	${RM} -f ${WRKSRC}/sys/system.se~

do-install:
	${CP} -r ${WRKSRC} ${PREFIX}

.include "../../mk/bsd.pkg.mk"
