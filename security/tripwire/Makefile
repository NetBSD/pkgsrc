# $NetBSD: Makefile,v 1.1.1.1 1998/11/17 16:27:25 agc Exp $
#

DISTNAME=       tripwire-1.2
CATEGORIES=	security
MASTER_SITES=   ftp://coast.cs.purdue.edu/pub/COAST/Tripwire/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.purdue.edu/coast/coast-library.html

post-extract:
	(cd ${WRKDIR}; /bin/pax -r < T1.2.tar)
	${CP} ${FILESDIR}/conf-netbsd.h ${WRKSRC}/configs

post-patch:
	${MV} ${WRKSRC}/include/config.h ${WRKSRC}/include/config.h.in
	${SED} -e 's|@localbase@|${LOCALBASE}|g' ${WRKSRC}/include/config.h.in \
		> ${WRKSRC}/include/config.h

post-install:
	${MKDIR} ${PREFIX}/share/doc/tripwire ${PREFIX}/etc/tripwire/databases
	${INSTALL_MAN} ${WRKSRC}/docs/designdoc.ps ${PREFIX}/share/doc/tripwire
	${SED} -e 's|@localbase@|${LOCALBASE}|g' -e 's|@x11base@|${X11BASE}|g' \
		${FILESDIR}/tw.conf.netbsd > ${PREFIX}/etc/tripwire/tripwire.conf

.include "../../mk/bsd.pkg.mk"
