# $NetBSD: Makefile,v 1.28 2002/09/20 21:13:39 jlam Exp $
#

DISTNAME=	vipec-2.0.4
PKGREVISION=		1
CATEGORIES=	cad
MASTER_SITES=	http://netfold.com/~vipec/public_ftp/stable/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.netfold.com/~vipec/
COMMENT=	Network analyser for electrical networks

USE_BUILDLINK2=		yes
USE_X11=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR}
CONFIGURE_ENV+=		USER_LDFLAGS="${LDFLAGS}"

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

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

.include "../../x11/qt2-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
