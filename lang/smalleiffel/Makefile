# $NetBSD: Makefile,v 1.1.1.1 1999/04/12 18:19:27 jlam Exp $
#

DISTNAME=	se
PKGNAME=	smalleiffel-0.79
WRKSRC=		${WRKDIR}/SmallEiffel
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.rit.edu/pub/mirrors/SmallEiffel/ \
		ftp://ftp.loria.fr/pub/loria/genielog/SmallEiffel/ \
		ftp://ftp.progsoc.uts.edu.au/pub/Eiffel/SmallEiffel/ \
		ftp://gd.tuwien.ac.at/pub/languages/SmallEiffel/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lamj@stat.cmu.edu
HOMEPAGE=	http://smalleiffel.loria.fr/

SE?=		${PREFIX}/lib/smalleiffel
BINNAME=	smalleiffel

post-extract:
	( cd ${WRKSRC}/sys; \
	  ${RM} compiler.* gc linker.* loadpath.* o_suffix.* system.se )
	( cd ${FILESDIR}; \
	  ${CP} compiler.UNIX gc linker.UNIX o_suffix.UNIX system.se \
		${WRKSRC}/sys )
	${SED} -e "s,@SE@,${SE},g" ${FILESDIR}/loadpath.UNIX \
		>${WRKSRC}/sys/loadpath.UNIX
	find ${WRKSRC} -type f -print | xargs ${CHMOD} 644

do-build:
	( cd ${WRKSRC}/bin_c; \
	  for f in clean compile_to_c compile_to_jvm \
		   compile finder pretty print_jvm_class short; \
	  do \
		${ECHO} Building $$f...; \
		${SH} -x $$f.make; \
		${CP} -f ${WRKSRC}/bin_c/$$f ${WRKSRC}/bin/$$f; \
	  done )
	${SED} -e "s,@@SE@@,${SE},g" \
		<${FILESDIR}/${BINNAME}.sh >${WRKDIR}/${BINNAME}.sh

do-install:
	${INSTALL_DATA_DIR} ${SE}
	for d in bin contrib lib_rand lib_se lib_show lib_std man \
		 short sys; do \
		( cd ${WRKSRC}; ${GTAR} cf - $$d ) \
			| ( cd ${SE}; ${GTAR} xvf - ); \
	done
	${CHOWN} -R ${LIBOWN}:${LIBGRP} ${SE}
	${CHOWN} -R ${BINOWN}:${BINGRP} ${SE}/bin
	${INSTALL_DATA} ${WRKSRC}/COPYING ${WRKSRC}/READ_ME ${SE}
	${INSTALL_DATA} ${WRKSRC}/misc/NOT_YET_IMPLEMENTED.* ${SE}/man
	${INSTALL_SCRIPT} ${WRKDIR}/${BINNAME}.sh ${PREFIX}/bin/${BINNAME}

.include "../../mk/bsd.pkg.mk"
