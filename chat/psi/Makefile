# $NetBSD: Makefile,v 1.11 2003/08/05 13:36:16 drochner Exp $

DISTNAME=	psi-0.9
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://belnet.dl.sourceforge.net/sourceforge/psi/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://psi.affinix.com/
COMMENT=	PSI Jabber Client

DEPENDS+=	psi-ssl>=2.0:../../chat/psi-ssl

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_X11BASE=	yes
HAS_CONFIGURE=	yes

CONFIGURE_ARGS+= -p ${PREFIX}

post-configure:
	${SED} -e 's:^CHK_DIR_EXISTS *= *$$:CHK_DIR_EXISTS=test -d:' -e "s:^MKDIR *= *$$:MKDIR=${MKDIR}:" -e "s:/bin/true:${TRUE}:" < ${BUILD_DIRS}/Makefile > ${BUILD_DIRS}/Makefile.orig
	${MV} ${BUILD_DIRS}/Makefile.orig ${BUILD_DIRS}/Makefile

do-install:
	cd ${WRKSRC} && ${QTDIR}/bin/lrelease psi.pro
	${INSTALL_DATA_DIR} ${X11BASE}/share/psi
	cd ${WRKSRC} && ${CP} -f -pR image iconsets sound certs lang/*.qm \
		README COPYING \
		${X11BASE}/share/psi/
	cd ${WRKSRC} && ${CP} -f psi ${X11BASE}/bin/psi

.include "../../x11/qt3-libs/buildlink2.mk"
BUILDLINK_DEPENDS.qt3-tools=	qt3-tools>=3.1.2nb2	# need lrelease
.include "../../x11/qt3-tools/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
