# $NetBSD: Makefile,v 1.1.1.1 1999/08/26 12:52:05 proff Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/07/12 22:59:19 steve Exp $

DISTNAME=       pcre-2.07
CATEGORIES=     devel
MASTER_SITES=   ftp://ftp.cus.cam.ac.uk/pub/software/programs/pcre/

MAINTAINER=	proff@netbsd.org

do-configure:
	${SED} -e '/^CC/s/.*/CC=${CC}/' \
	       -e '/^CFLAGS/s/.*/CFLAGS=${CFLAGS}/' \
	       -e '/^RANLIB/s/.*/RANLIB=${RANLIB}/' \
	    ${WRKSRC}/Makefile > ${WRKSRC}/Makefile.new
	${MV} ${WRKSRC}/Makefile.new ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgrep ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libpcre.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/pcre.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/pcre.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/pcreposix.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/pgrep.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
