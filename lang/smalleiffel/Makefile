# $NetBSD: Makefile,v 1.3 1999/10/12 08:01:33 jlam Exp $
#

DISTNAME=	se
PKGNAME=	smalleiffel-0.78
WRKSRC=		${WRKDIR}/SmallEiffel
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.loria.fr/pub/loria/genielog/SmallEiffel/ \
		ftp://ftp.cs.rit.edu/pub/mirrors/SmallEiffel/ \
		ftp://ftp.progsoc.uts.edu.au/pub/Eiffel/SmallEiffel/ \
		ftp://gd.tuwien.ac.at/pub/languages/SmallEiffel/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://smalleiffel.loria.fr/

DOCDIR=		${PREFIX}/share/doc/smalleiffel
EGDIR=		${PREFIX}/share/examples/smalleiffel
LIBDIR=		${PREFIX}/share/smalleiffel
LIBEXECDIR=	${PREFIX}/libexec/smalleiffel

BINNAME=	smalleiffel
SE_BINARIES=	clean compile compile_to_c compile_to_jvm \
		finder pretty print_jvm_class short

post-extract:
	find ${WRKSRC} -type f -print | xargs ${CHMOD} 644
	find ${WRKSRC} -name ".gdb*" -print | xargs ${RM} -f
	cd ${WRKSRC}/man; ${RM} -f *.txt
	cd ${WRKSRC}/sys; ${RM} -f compiler.se gc loadpath.* system.se
	cd ${FILESDIR}; \
		${CP} -f compiler.se gc loadpath.UNIX system.se ${WRKSRC}/sys

post-patch:
	cd ${WRKSRC}/lib_se; \
		${RM} -f frozen_string_list.e.orig system_tools.e.orig

do-build:
	@${ECHO} '*** Building Eiffel compiler system (pass 1) ***'
	@cd ${WRKSRC}/bin_c; \
	for file in ${SE_BINARIES}; do \
		${ECHO} Building $$file...; \
		${SH} $$file.make; \
		${CP} -f ${WRKSRC}/bin_c/$$file ${WRKSRC}/bin/$$file; \
	done; \
	${RM} -f *

	@${ECHO} '*** Building Eiffel compiler system (pass 2) ***'
	@cd ${WRKSRC}/bin_c; \
	for file in ${SE_BINARIES}; do \
		${ECHO} Building $$file...; \
		SMALLEIFFEL=${WRKSRC} SmallEiffel=${WRKSRC}/sys/system.se \
			../bin/compile -boost -no_split -o $$file $$file; \
	done

post-build:
	${SED}	-e "s,@@SE_LIB@@,${LIBDIR},g" \
		-e "s,@@SE_LIBEXEC@@,${LIBEXECDIR},g" \
		${FILESDIR}/${BINNAME}.sh > ${WRKDIR}/${BINNAME}.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${BINNAME}.sh ${PREFIX}/bin/${BINNAME}
	${INSTALL_PROGRAM_DIR} ${LIBEXECDIR}
	for file in ${SE_BINARIES}; do \
		${INSTALL_PROGRAM} ${WRKSRC}/bin_c/$$file ${LIBEXECDIR}; \
	done
	${INSTALL_DATA_DIR} ${LIBDIR}
	cd ${WRKSRC}; \
	for dir in lib_rand lib_se lib_std short sys; do \
		${PAX} -rw $$dir ${LIBDIR}; \
	done
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${LIBDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/misc/NOT_YET_IMPLEMENTED.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/misc/WeNeedFeedBack.txt ${DOCDIR}
	cd ${WRKSRC}/man; ${INSTALL_DATA} *.html *.gif *.FAQ ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}; \
	for dir in contrib lib_show; do \
		${PAX} -rw $$dir ${EGDIR}; \
	done
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EGDIR}

.include "../../mk/bsd.pkg.mk"
