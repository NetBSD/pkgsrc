# $NetBSD: Makefile,v 1.17 2000/08/28 19:52:33 dmcmahill Exp $
#

DISTNAME=	vipec-2.0.4
CATEGORIES=	cad
MASTER_SITES=	http://netfold.com/~vipec/public_ftp/stable/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.netfold.com/~vipec/

DEPENDS+=	qt21-2.1.1:../../x11/qt21

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_X11=	yes

EVAL_PREFIX+=	QT2DIR=qt21
CONFIGURE_ENV+=	"QTDIR=${QT2DIR}/qt21" \
		all_libraries="-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib -Wl,-R${X11BASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS+=	"--with-qt-dir=${QT2DIR}/qt21"

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

.include "../../mk/bsd.pkg.mk"
