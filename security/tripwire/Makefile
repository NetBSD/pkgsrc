# $NetBSD: Makefile,v 1.9 2003/04/10 20:10:20 grant Exp $
#

DISTNAME=       tripwire-1.2
CATEGORIES=	security
MASTER_SITES=   ftp://coast.cs.purdue.edu/pub/tools/unix/ids/tripwire/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cerias.purdue.edu/coast/coast-library.html
COMMENT=	File and directory integrity checker

post-extract:
	cd ${WRKDIR} && ${PAX} -O -rf T1.2.tar
	${CP} ${FILESDIR}/conf-${LOWER_OPSYS}.h ${WRKSRC}/configs

post-patch:
	${MV} ${WRKSRC}/include/config.h ${WRKSRC}/include/config.h.in
	${SED} -e 's|@localbase@|${LOCALBASE}|g'			\
		-e 's|@LOWER_OPSYS@|${LOWER_OPSYS}|g'			\
		${WRKSRC}/include/config.h.in > ${WRKSRC}/include/config.h

PRE_ROOT_CMD=	${CHMOD} -R go+rwx ${WRKDIR}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tripwire
	${INSTALL_DATA_DIR} ${PREFIX}/etc/tripwire/databases
	${INSTALL_DATA} ${WRKSRC}/docs/designdoc.ps ${PREFIX}/share/doc/tripwire
	${SED} -e 's|@localbase@|${LOCALBASE}|g' -e 's|@x11base@|${X11BASE}|g' \
		${FILESDIR}/tw.conf.${LOWER_OPSYS} > ${PREFIX}/etc/tripwire/tripwire.conf

.include "../../mk/bsd.pkg.mk"
