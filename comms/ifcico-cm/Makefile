# $NetBSD: Makefile,v 1.8 2002/07/06 19:05:53 tv Exp $
#

DISTNAME=	ifcico-3.0.cm.alpha-4.1
PKGNAME=	ifcico-cm-3.0a4.1
CATEGORIES=	comms
MASTER_SITES=	http://cmeerw.org/files/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://cmeerw.org/ifcico/
COMMENT=	FidoNet transport program using FTS protocols via dial or TCP

USE_BUILDLINK_ONLY=	# defined

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g' ${WRKSRC}/misc/config >${WRKDIR}/config.dist
	${SED} -e 's,@PREFIX@,${PREFIX},g' ${WRKSRC}/misc/config-global \
		>${WRKDIR}/config-global.dist

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/ifcico
	${INSTALL_DATA} ${WRKDIR}/config* ${PREFIX}/etc/ifcico/
	cd ${WRKSRC}/ifcico && for f in *.8; do \
		tbl <$$f >$$f.t && ${INSTALL_DATA} $$f.t ${PREFIX}/man/man8/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
