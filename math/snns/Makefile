# $NetBSD: Makefile,v 1.1.1.1 2001/06/28 15:18:03 wulf Exp $

DISTNAME=	SNNSv4.2
PKGNAME=	snns-4.2
CATEGORIES=	misc
MASTER_SITES=	http://www-ra.informatik.uni-tuebingen.de/downloads/SNNS/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://www-ra.informatik.uni-tuebingen.de/SNNS/
COMMENT=	Software simulator for neural networks

GNU_CONFIGURE=	YES
CONFIGURE_ARGS= --enable-global --prefix=${LOCALBASE}

XGUILOADPATH=	${LOCALBASE}/share/snns

post-install:
		${INSTALL_DATA_DIR} ${XGUILOADPATH};
		${INSTALL_DATA_DIR} ${LOCALBASE}/share/snns;
		${INSTALL_DATA_DIR} ${LOCALBASE}/share/doc/snns;
		${INSTALL_DATA_DIR} ${LOCALBASE}/share/examples/snns;
		${INSTALL_DATA} ${WRKSRC}/help.hdoc ${XGUILOADPATH};
		${INSTALL_DATA} ${WRKSRC}/default.cfg ${XGUILOADPATH};
		cd ${WRKSRC} && ${MAKE} install-man;
		for i in `ls -1 ${WRKSRC}/tools/doc`; do \
		  ${INSTALL_DATA} ${WRKSRC}/tools/doc/$$i \
		    ${LOCALBASE}/share/doc/snns; \
		done
		for i in `ls -1 ${WRKSRC}/examples`; do \
		  ${INSTALL_DATA} ${WRKSRC}/examples/$$i \
		    ${LOCALBASE}/share/examples/snns; \
		done

.include "../../mk/bsd.pkg.mk"
