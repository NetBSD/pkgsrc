# $NetBSD: Makefile,v 1.6 2008/05/26 22:37:30 tnn Exp $

DISTNAME=	se
PKGNAME=	SmartEiffel-2.0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.loria.fr/pub/loria/SmartEiffel/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	lars.nordlund@hem.utfors.se
HOMEPAGE=	http://smarteiffel.loria.fr/
COMMENT=	The GNU Eiffel Compiler

PKG_DESTDIR_SUPPORT=	user-destdir
NOT_FOR_BULK_PLATFORM=	HPUX-*-*

WRKSRC=		${WRKDIR}/SmartEiffel

DIST_SUBDIR=	${PKGNAME_NOREV}

MAKE_ENV+=	SmartEiffel=${WRKSRC:Q}/sys/system.se

# This package relies heavily on GCC.
ONLY_FOR_COMPILER=	gcc

CHECK_INTERPRETER_SKIP=	SmartEiffel/contrib/edb/sec \
			  SmartEiffel/misc/benchmarks/all_bench.elate \
			  SmartEiffel/www/libraries/eiffeldoc.sh
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
	${CP} -r ${WRKSRC} ${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
