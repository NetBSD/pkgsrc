# $NetBSD: Makefile,v 1.7 2000/02/25 05:11:58 jlam Exp $
#

DISTNAME=	se
PKGNAME=	smalleiffel-0.77
WRKSRC=		${WRKDIR}/SmallEiffel
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.loria.fr/pub/loria/genielog/SmallEiffel/ \
		ftp://ftp.cs.rit.edu/pub/mirrors/SmallEiffel/ \
		ftp://ftp.progsoc.uts.edu.au/pub/Eiffel/SmallEiffel/ \
		ftp://gd.tuwien.ac.at/pub/languages/SmallEiffel/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://smalleiffel.loria.fr/

MAKE_ENV+=	SmallEiffel=${WRKSRC}/sys/system.se
ALL_TARGET=	./bin/compile_to_c

DIST_SUBDIR=	${PKGNAME}
DOCDIR=		share/doc/smalleiffel
EGDIR=		share/examples/smalleiffel
LIBDIR=		share/smalleiffel
LIBEXECDIR=	libexec/smalleiffel

post-extract:
	${FIND} ${WRKSRC} -type f -print0 | xargs -0 ${CHMOD} 644

post-patch:
	${CHMOD} +x ${WRKSRC}/misc/GC.SH

post-build:
	${SED}	-e "s,@@SE_LIB@@,${PREFIX}/${LIBDIR},g" \
		-e "s,@@SE_LIBEXEC@@,${PREFIX}/${LIBEXECDIR},g" \
		${FILESDIR}/smalleiffel.sh > ${WRKDIR}/smalleiffel.sh
	${SED}	-e "s,@@SE_LIB@@,${PREFIX}/${LIBDIR},g" \
		${FILESDIR}/loadpath.UNIX.in > ${WRKDIR}/loadpath.UNIX

pre-install:
	${RM} -f ${WRKSRC}/sys/loadpath.*
	${FIND} ${WRKSRC} -name ".gdb*" -print0 | xargs -0 ${RM} -f
	${FIND} ${WRKSRC} -name "*.orig" -print0 | xargs -0 ${RM} -f

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/smalleiffel.sh ${PREFIX}/bin/smalleiffel

	${INSTALL_PROGRAM_DIR} ${PREFIX}/${LIBEXECDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/${LIBEXECDIR}

	${INSTALL_DATA_DIR} ${PREFIX}/${LIBDIR}
	cd ${WRKSRC}; for dir in \
	    lib_iterator lib_number lib_random lib_se lib_std short sys; do \
		${PAX} -rw $${dir} ${PREFIX}/${LIBDIR}; \
	done
	${INSTALL_DATA} ${WRKDIR}/loadpath.UNIX ${PREFIX}/${LIBDIR}/sys
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${LIBDIR}

	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	${INSTALL_DATA} \
		${WRKSRC}/COPYING \
		${WRKSRC}/misc/WeNeedFeedBack.txt \
		${PREFIX}/${DOCDIR}
	cd ${WRKSRC}/misc; \
		${INSTALL_DATA} \
			HISTORY.html NOT_YET_IMPLEMENTED.html \
			THANKS.html people.html \
			${PREFIX}/${DOCDIR}
	cd ${WRKSRC}/man; \
		${INSTALL_DATA} Eiffel.FAQ *.html *.gif ${PREFIX}/${DOCDIR}

	${INSTALL_DATA_DIR} ${PREFIX}/${EGDIR}
	cd ${WRKSRC}; for dir in contrib lib_show; do \
		${PAX} -rw $${dir} ${PREFIX}/${EGDIR}; \
	done
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${EGDIR}

.include "../../mk/bsd.pkg.mk"
