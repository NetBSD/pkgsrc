# $NetBSD: Makefile,v 1.5 1999/01/01 23:42:58 garbled Exp $

DISTNAME=		pvm3.4.beta7
PKGNAME=		pvm-3.4.7
CATEGORIES=		parallel
MASTER_SITES=		http://www.netlib.org/pvm3/
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.netlib.org/

#DEPENDS+=		ssh-1.2.26:../../security/ssh

WRKSRC=			${WRKDIR}/pvm3
MAKE_ENV+=		PVM_ROOT=${WRKSRC}
ALL_TARGET=		all install

_HAVE_F77!= if [ -e /usr/bin/f77 ]; then echo "YES"; else echo "NO"; fi

.if (${_HAVE_F77} == "YES")
F77= /usr/bin/f77
.else
F77=f2c
BUILD_DEPENDS+=		f2c:../../lang/f2c
.endif
MAKE_FLAGS+=		F77=${F77}

post-patch:
	@${MV} ${WRKSRC}/lib/pvm ${WRKSRC}/lib/pvm.in
	@${SED} -e 's@XXPKGXX@${LOCALBASE}@g' < ${WRKSRC}/lib/pvm.in > ${WRKSRC}/lib/pvm
	@${MV} ${WRKSRC}/lib/pvmd ${WRKSRC}/lib/pvmd.in
	@${SED} -e 's@XXPKGXX@${LOCALBASE}@g' < ${WRKSRC}/lib/pvmd.in > ${WRKSRC}/lib/pvmd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/NETBSD/* ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/lib/NETBSD/pvmd3 ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/lib/NETBSD/pvm ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/lib/pvm ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/lib/pvmd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/NETBSD/libpvm3.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/NETBSD/libfpvm3.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/NETBSD/libgpvm3.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/NETBSD/libpvmtrc.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/man3/* ${PREFIX}/man/man3

.include "../../mk/bsd.pkg.mk"
