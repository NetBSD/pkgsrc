# $NetBSD: Makefile,v 1.2 1998/10/14 08:31:17 frueauf Exp $

DISTNAME=		pvm3.4.beta6
PKGNAME=		pvm-3.4.6
CATEGORIES=		parallel
MASTER_SITES=		http://www.netlib.org/pvm3/
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.netlib.org/

DEPENDS+=		ssh-1.2.26:../../security/ssh

WRKSRC=			${WRKDIR}/pvm3
MAKE_ENV+=		PVM_ROOT=${WRKSRC}
ALL_TARGET=		all install

post-patch:
	@${MV} ${WRKSRC}/lib/pvm ${WRKDIR}/foo
	@${SED} -e 's@XXPKGXX@${LOCALBASE}@g' < ${WRKDIR}/foo > ${WRKSRC}/lib/pvm
	@${MV} ${WRKSRC}/lib/pvmd foo
	@${SED} -e 's@XXPKGXX@${LOCALBASE}@g' < ${WRKDIR}/foo > ${WRKSRC}/lib/pvmd
	@${RM} ${WRKDIR}/foo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/NETBSD/* ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/lib/NETBSD/pvmd3 ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/lib/NETBSD/pvm ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/lib/pvm ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/lib/pvmd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/NETBSD/libpvm3.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/NETBSD/libpvmtrc.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/man3/* ${PREFIX}/man/man3

.include "../../mk/bsd.pkg.mk"
