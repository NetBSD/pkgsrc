# $NetBSD: Makefile,v 1.6 2002/03/19 08:48:17 skrll Exp $

DISTNAME=	SNNSv4.2
PKGNAME=	snns-4.2
CATEGORIES=	misc
MASTER_SITES=	http://www-ra.informatik.uni-tuebingen.de/downloads/SNNS/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://www-ra.informatik.uni-tuebingen.de/SNNS/
COMMENT=	Software simulator for neural networks

USE_XPM=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS= --enable-global --prefix=${LOCALBASE}

XGUILOADPATH=	${LOCALBASE}/share/snns

AUTOMAKE_PATTERNS+= \
		config.hin

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
