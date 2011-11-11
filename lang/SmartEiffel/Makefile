# $NetBSD: Makefile,v 1.9 2011/11/11 08:29:06 sbd Exp $

DISTNAME=	se
PKGNAME=	SmartEiffel-2.0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.loria.fr/pub/loria/SmartEiffel/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	lars.nordlund@hem.utfors.se
HOMEPAGE=	http://smarteiffel.loria.fr/
COMMENT=	The GNU Eiffel Compiler

PKG_DESTDIR_SUPPORT=	user-destdir
NOT_FOR_BULK_PLATFORM=	Linux-*-*

WRKSRC=		${WRKDIR}/SmartEiffel
USE_TOOLS+=	pax

DIST_SUBDIR=	${PKGNAME_NOREV}

MAKE_ENV+=	SmartEiffel=${WRKSRC:Q}/sys/system.se

# This package relies heavily on GCC.
ONLY_FOR_COMPILER=	gcc

CHECK_INTERPRETER_SKIP=	SmartEiffel/contrib/edb/sec \
			  SmartEiffel/misc/benchmarks/all_bench.elate \
			  SmartEiffel/www/libraries/eiffeldoc.sh

REPLACE_PYTHON+=	contrib/htmldoc/htmlshort

post-patch:
	${SED} "s:XXXWORKDIRXXX:${WRKDIR}:g" ${FILESDIR}/system.se \
		> ${WRKSRC}/sys/system.se

post-build:
	${MV} -f ${WRKSRC}/sys/system.se ${WRKSRC}/sys/system.se.bak
	${SED} "s:${WRKDIR}:${PREFIX}:g" ${WRKSRC}/sys/system.se.bak > \
		${WRKSRC}/sys/system.se
	${RM} -f ${WRKSRC}/sys/system.se.bak
	${RM} -f ${WRKSRC}/sys/system.se~
	${RM} -f ${WRKSRC}/Makefile.orig

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/SmartEiffel
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/SmartEiffel

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
