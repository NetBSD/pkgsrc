# $NetBSD: Makefile,v 1.20 2001/05/24 19:51:07 dmcmahill Exp $

DISTNAME=		pvm3.4.3
PKGNAME=		pvm-3.4.3
CATEGORIES=		parallel
MASTER_SITES=		http://www.netlib.org/pvm3/
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.epm.ornl.gov/pvm/pvm_home.html
COMMENT=		Parallel Virtual Machine libraries and environment

.if exists(/usr/bin/ssh)
PVM_SSH?=		/usr/bin/ssh
.else
DEPENDS+=		{openssh-*,ssh{,6}-1.2.27*}:../../security/ssh
PVM_SSH?=		${LOCALBASE}/bin/ssh
.endif

USE_FORTRAN=		yes
USE_X11=		yes
WRKSRC=			${WRKDIR}/pvm3
MAKE_ENV+=		PVM_ROOT=${WRKSRC}
MAKE_ENV+=		PVM_ARCH=
MAKE_ENV+=		SSH=${PVM_SSH}
ALL_TARGET=		all install
PLIST_SRC=		${WRKDIR}/PLIST-src

PVM_DIR=		${PREFIX}/pvm3

do-install:
	PVM_ARCH=`${PVM_ROOT}/lib/pvmgetarch` ; export PVM_ARCH ;\
	${INSTALL_PROGRAM_DIR} ${PVM_DIR}/bin/$$PVM_ARCH ;\
	${INSTALL_PROGRAM} ${WRKSRC}/bin/$$PVM_ARCH/* ${PVM_DIR}/bin/$$PVM_ARCH  ;\
	${INSTALL_DATA_DIR} ${PVM_DIR}/conf ;\
	${INSTALL_DATA} ${WRKSRC}/conf/$$PVM_ARCH.def  ${PVM_DIR}/conf ;\
	${INSTALL_DATA} ${WRKSRC}/conf/$$PVM_ARCH.m4  ${PVM_DIR}/conf ;\
	${INSTALL_DATA_DIR} ${PVM_DIR}/examples ;\
	${INSTALL_DATA} ${WRKSRC}/examples/*.c  ${PVM_DIR}/examples ;\
	${INSTALL_DATA} ${WRKSRC}/examples/*.f  ${PVM_DIR}/examples ;\
	${INSTALL_DATA} ${WRKSRC}/examples/Readme  ${PVM_DIR}/examples ;\
	${INSTALL_DATA} ${WRKSRC}/examples/Makefile.aimk  ${PVM_DIR}/examples ;\
	${INSTALL_DATA_DIR} ${PVM_DIR}/gexamples ;\
	${INSTALL_DATA} ${WRKSRC}/gexamples/*.c  ${PVM_DIR}/gexamples ;\
	${INSTALL_DATA} ${WRKSRC}/gexamples/*.f  ${PVM_DIR}/gexamples ;\
	${INSTALL_DATA} ${WRKSRC}/gexamples/Readme  ${PVM_DIR}/gexamples ;\
	${INSTALL_DATA} ${WRKSRC}/gexamples/Makefile.aimk  ${PVM_DIR}/gexamples ;\
	${INSTALL_DATA} ${WRKSRC}/gexamples/Makefile  ${PVM_DIR}/gexamples ;\
	${INSTALL_DATA_DIR} ${PVM_DIR}/include ;\
	${INSTALL_DATA} ${WRKSRC}/include/* ${PVM_DIR}/include ;\
	${INSTALL_PROGRAM_DIR} ${PVM_DIR}/lib/$$PVM_ARCH ;\
	${INSTALL_PROGRAM} ${WRKSRC}/lib/$$PVM_ARCH/pvm* ${PVM_DIR}/lib/$$PVM_ARCH ;\
	${INSTALL_DATA} ${WRKSRC}/lib/$$PVM_ARCH/*.a ${PVM_DIR}/lib/$$PVM_ARCH ;\
	for f in `ls ${WRKSRC}/lib` ; do \
	  if [ -f ${WRKSRC}/lib/$$f ]; then \
	    ${INSTALL_SCRIPT} ${WRKSRC}/lib/$$f ${PVM_DIR}/lib ;\
	  fi ;\
	done ;\
	${INSTALL_MAN_DIR}  ${PREFIX}/man/man1 ;\
	${INSTALL_MAN_DIR}  ${PREFIX}/man/man3 ;\
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${PREFIX}/man/man1 ;\
	${INSTALL_MAN} ${WRKSRC}/man/man3/* ${PREFIX}/man/man3 ;\
	${RM} ${PREFIX}/man/man1/PVM.1 ;\
	${LN} -s ${PREFIX}/man/man1/pvm_intro.1 ${PREFIX}/man/man1/PVM.1

post-install:
	${SED} "s/@pvmarch@/`${PVM_ROOT}/lib/pvmgetarch`/g" < ${PKGDIR}/PLIST > ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
