# $NetBSD: Makefile,v 1.16 2004/04/24 22:46:11 jlam Exp $
#

DISTNAME=	${PKGNAME:S/smalleiffel/se/}
PKGNAME=	smalleiffel-0.77
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.loria.fr/pub/loria/genielog/SmallEiffel/Oldies/ \
		ftp://ftp.cs.rit.edu/pub/mirrors/SmallEiffel/Oldies/ \
		ftp://ftp.progsoc.uts.edu.au/pub/Eiffel/SmallEiffel/Oldies/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://smalleiffel.loria.fr/
COMMENT=	GNU Eiffel compiler

MAKE_ENV+=	SmallEiffel=${WRKSRC}/sys/system.se
ALL_TARGET=	./bin/compile_to_c

WRKSRC=		${WRKDIR}/SmallEiffel
DOCDIR=		${PREFIX}/share/doc/html/smalleiffel
EGDIR=		${PREFIX}/share/examples/smalleiffel
LIBDIR=		${PREFIX}/share/smalleiffel
LIBEXECDIR=	${PREFIX}/libexec/smalleiffel

post-extract:
	${FIND} ${WRKSRC} -type f -print | ${XARGS} ${CHMOD} 644

post-patch:
	${CHMOD} +x ${WRKSRC}/misc/GC.SH

post-build:
	${SED}	-e "s,@@SE_DOC@@,${DOCDIR},g" \
		-e "s,@@SE_LIB@@,${LIBDIR},g" \
		-e "s,@@SE_LIBEXEC@@,${LIBEXECDIR},g" \
		${FILESDIR}/smalleiffel.sh > ${WRKDIR}/smalleiffel.sh
	${SED}	-e "s,@@SE_LIB@@,${LIBDIR},g" \
		${FILESDIR}/loadpath.UNIX.in > ${WRKDIR}/loadpath.UNIX

pre-install:
	${RM} -f ${WRKSRC}/sys/loadpath.*
	${FIND} ${WRKSRC} -name ".gdb*" -print | ${XARGS} ${RM} -f
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/smalleiffel.sh ${PREFIX}/bin/smalleiffel

	${INSTALL_PROGRAM_DIR} ${LIBEXECDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${LIBEXECDIR}

	${INSTALL_DATA_DIR} ${LIBDIR}
	cd ${WRKSRC}; for dir in \
	    lib_iterator lib_number lib_random lib_se lib_std short sys; do \
		${PAX} -rw $${dir} ${LIBDIR}; \
	done
	${INSTALL_DATA} ${WRKDIR}/loadpath.UNIX ${LIBDIR}/sys
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${LIBDIR}

	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING misc/WeNeedFeedBack.txt ${DOCDIR}
	cd ${WRKSRC}/misc; ${INSTALL_DATA} \
		HISTORY.html NOT_YET_IMPLEMENTED.html THANKS.html people.html \
		${DOCDIR}
	cd ${WRKSRC}/man; ${INSTALL_DATA} Eiffel.FAQ *.html *.gif ${DOCDIR}

	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}; for dir in contrib lib_show; do \
		${PAX} -rw $${dir} ${EGDIR}; \
	done
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EGDIR}

.include "../../mk/bsd.pkg.mk"
