# $NetBSD: Makefile,v 1.5 2000/03/28 21:48:41 dmcmahill Exp $
#

DISTNAME=	vipec-2.0.1
CATEGORIES=	cad
MASTER_SITES=	http://netfold.com/~vipec/public_ftp/stable/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.netfold.com/~vipec/

DEPENDS+=	qt-2.0.2:../../x11/qt

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_X11=	yes

CONFIGURE_ENV+=	"QTDIR=${X11BASE}/qt2"

post-extract:
	${MV} -f ${WRKSRC}/bin/start_vipec_help ${WRKSRC}/bin/start_vipec_help.in

pre-configure:
	${RM} -f ${WRKSRC}/config.cache

post-configure:
	${SED} 's;@prefix@;${PREFIX};g' ${WRKSRC}/bin/start_vipec_help.in > ${WRKSRC}/bin/start_vipec_help

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vipec/vipec ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/start_vipec_help ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vipec
	${INSTALL_DATA} ${WRKSRC}/vipec/ckt/*.ckt ${PREFIX}/share/examples/vipec
	${INSTALL_DATA} ${WRKSRC}/vipec/ckt/*.s2p ${PREFIX}/share/examples/vipec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vipec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vipec/models
	${INSTALL_DATA} ${WRKSRC}/vipec/help/*.html ${PREFIX}/share/doc/vipec
	${INSTALL_DATA} ${WRKSRC}/vipec/help/*.gif ${PREFIX}/share/doc/vipec
	${INSTALL_DATA} ${WRKSRC}/vipec/help/models/*.html ${PREFIX}/share/doc/vipec/models
	${INSTALL_DATA} ${WRKSRC}/vipec/help/models/*.gif ${PREFIX}/share/doc/vipec/models

.include "../../mk/bsd.pkg.mk"
