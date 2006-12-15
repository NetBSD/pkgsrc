# $NetBSD: Makefile,v 1.18 2006/12/15 20:32:58 joerg Exp $

DISTNAME=	SNNSv4.2
PKGNAME=	snns-4.2
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www-ra.informatik.uni-tuebingen.de/downloads/SNNS/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www-ra.informatik.uni-tuebingen.de/SNNS/
COMMENT=	Software simulator for neural networks

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-global

XGUILOADPATH=	${PREFIX}/share/snns

post-install:
		${INSTALL_DATA_DIR} ${XGUILOADPATH};
		${INSTALL_DATA_DIR} ${PREFIX}/share/snns;
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snns;
		${INSTALL_DATA_DIR} ${PREFIX}/share/examples/snns;
		${INSTALL_DATA} ${WRKSRC}/help.hdoc ${XGUILOADPATH};
		${INSTALL_DATA} ${WRKSRC}/default.cfg ${XGUILOADPATH};
		cd ${WRKSRC} && ${MAKE} install-man;
		for i in `ls -1 ${WRKSRC}/tools/doc`; do \
		  ${INSTALL_DATA} ${WRKSRC}/tools/doc/$$i \
		    ${PREFIX}/share/doc/snns; \
		done
		for i in `ls -1 ${WRKSRC}/examples`; do \
		  ${INSTALL_DATA} ${WRKSRC}/examples/$$i \
		    ${PREFIX}/share/examples/snns; \
		done

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
