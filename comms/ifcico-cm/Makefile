# $NetBSD: Makefile,v 1.5 2001/02/21 18:50:36 tv Exp $
#

DISTNAME=	ifcico-3.0.cm.alpha-4.1
PKGNAME=	ifcico-cm-3.0a4.1
CATEGORIES=	comms
MASTER_SITES=	http://www.cosy.sbg.ac.at/~cmeer/files/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.cosy.sbg.ac.at/~cmeer/ifcico/
COMMENT=	FidoNet transport program using FTS protocols via dial or TCP

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g' ${WRKSRC}/misc/config >${WRKDIR}/config.dist
	${SED} -e 's,@PREFIX@,${PREFIX},g' ${WRKSRC}/misc/config-global \
		>${WRKDIR}/config-global.dist

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/ifcico
	${INSTALL_DATA} ${WRKDIR}/config* ${PREFIX}/etc/ifcico/
	cd ${WRKSRC}/ifcico && ${INSTALL_MAN} *.8 ${PREFIX}/man/man8/

.include "../../mk/bsd.pkg.mk"
