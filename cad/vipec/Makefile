# $NetBSD: Makefile,v 1.25 2001/10/23 13:14:46 jlam Exp $
#

DISTNAME=	vipec-2.0.4
CATEGORIES=	cad
MASTER_SITES=	http://netfold.com/~vipec/public_ftp/stable/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.netfold.com/~vipec/
COMMENT=	Network analyser for electrical networks

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_BUILDLINK_ONLY=	yes

CONFIGURE_ARGS+=	--with-qt-dir=${BUILDLINK_QTDIR}
CONFIGURE_ENV+=		USER_LDFLAGS="${LDFLAGS}"

post-patch:
	${MV} -f ${WRKSRC}/vipec/helpwindow.cpp ${WRKSRC}/vipec/helpwindow.cpp.in
	${SED} "s;@prefix@;${PREFIX};g" ${WRKSRC}/vipec/helpwindow.cpp.in > \
		${WRKSRC}/vipec/helpwindow.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vipec/vipec ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vipec
	${INSTALL_DATA} ${WRKSRC}/vipec/ckt/*.ckt ${PREFIX}/share/examples/vipec
	${INSTALL_DATA} ${WRKSRC}/vipec/ckt/*.s2p ${PREFIX}/share/examples/vipec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vipec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vipec/models
	${INSTALL_DATA} ${WRKSRC}/vipec/help/*.html ${PREFIX}/share/doc/vipec
	${INSTALL_DATA} ${WRKSRC}/vipec/help/*.png ${PREFIX}/share/doc/vipec
	${INSTALL_DATA} ${WRKSRC}/vipec/help/models/*.html ${PREFIX}/share/doc/vipec/models
	${INSTALL_DATA} ${WRKSRC}/vipec/help/models/*.png ${PREFIX}/share/doc/vipec/models

.include "../../mk/x11.buildlink.mk"
.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
