# $NetBSD: Makefile,v 1.24 2012/09/13 21:43:08 asau Exp $

DISTNAME=	SNNSv4.3
PKGNAME=	snns-4.3
CATEGORIES=	misc
MASTER_SITES=	http://www-ra.informatik.uni-tuebingen.de/downloads/SNNS/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www-ra.informatik.uni-tuebingen.de/SNNS/
COMMENT=	Software simulator for neural networks

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-global

XGUILOADPATH=	${PREFIX}/share/snns

INSTALLATION_DIRS+=	share/snns share/doc/snns \
			share/examples/snns

INSTALL_TARGET=		install install-man
INSTALL_MAKE_FLAGS+=	INSTALLDIR=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/help.hdoc ${DESTDIR}${XGUILOADPATH}
	${INSTALL_DATA} ${WRKSRC}/default.cfg ${DESTDIR}${XGUILOADPATH}
	for i in `ls -1 ${WRKSRC}/tools/doc`; do \
		${INSTALL_DATA} ${WRKSRC}/tools/doc/$$i \
			${DESTDIR}${PREFIX}/share/doc/snns; \
	done
	for i in `ls -1 ${WRKSRC}/examples`; do \
		${INSTALL_DATA} ${WRKSRC}/examples/$$i \
		    ${DESTDIR}${PREFIX}/share/examples/snns; \
	done

.include "../../x11/Xaw3d/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
