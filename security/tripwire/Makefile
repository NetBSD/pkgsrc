# $NetBSD: Makefile,v 1.4 2000/12/09 13:37:47 wiz Exp $
#

DISTNAME=       tripwire-1.2
CATEGORIES=	security
MASTER_SITES=   ftp://coast.cs.purdue.edu/pub/tools/unix/ids/tripwire/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cerias.purdue.edu/coast/coast-library.html

post-extract:
	(cd ${WRKDIR}; ${PAX} -r < T1.2.tar)
	${CP} ${FILESDIR}/conf-${LOWER_OPSYS}.h ${WRKSRC}/configs

post-patch:
	${MV} ${WRKSRC}/include/config.h ${WRKSRC}/include/config.h.in
	${SED} -e 's|@localbase@|${LOCALBASE}|g'			\
		-e 's|@LOWER_OPSYS@|${LOWER_OPSYS}|g'			\
		${WRKSRC}/include/config.h.in > ${WRKSRC}/include/config.h

PRE_ROOT_CMD=	${CHMOD} -R go+rwx ${WRKDIR}

post-install:
	${MKDIR} ${PREFIX}/share/doc/tripwire ${PREFIX}/etc/tripwire/databases
	${INSTALL_MAN} ${WRKSRC}/docs/designdoc.ps ${PREFIX}/share/doc/tripwire
	${SED} -e 's|@localbase@|${LOCALBASE}|g' -e 's|@x11base@|${X11BASE}|g' \
		${FILESDIR}/tw.conf.${LOWER_OPSYS} > ${PREFIX}/etc/tripwire/tripwire.conf

.include "../../mk/bsd.pkg.mk"
