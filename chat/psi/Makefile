# $NetBSD: Makefile,v 1.16 2004/04/25 22:50:48 snj Exp $

DISTNAME=	psi-0.9
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=psi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://psi.affinix.com/
COMMENT=	PSI Jabber Client

DEPENDS+=	psi-ssl>=2.0:../../chat/psi-ssl

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
USE_X11=	yes
HAS_CONFIGURE=	yes

CONFIGURE_ARGS+= -p ${PREFIX}

post-configure:
	${SED} \
	-e 's:^CHK_DIR_EXISTS *= *$$:CHK_DIR_EXISTS=test -d:' \
	-e "s:^MKDIR *= *$$:MKDIR=${MKDIR}:" \
	-e "s:/bin/true:${TRUE}:" < ${BUILD_DIRS}/Makefile \
		> ${BUILD_DIRS}/Makefile.orig
	${MV} ${BUILD_DIRS}/Makefile.orig ${BUILD_DIRS}/Makefile

do-install:
	cd ${WRKSRC} && ${QTDIR}/bin/lrelease psi.pro
	${INSTALL_DATA_DIR} ${PREFIX}/share/psi
	cd ${WRKSRC} && ${CP} -f -pR image iconsets sound certs lang/*.qm \
		README COPYING \
		${PREFIX}/share/psi/
	cd ${WRKSRC} && ${CP} -f psi ${PREFIX}/bin/psi

.include "../../x11/qt3-libs/buildlink3.mk"
BUILDLINK_DEPENDS.qt3-tools=	qt3-tools>=3.1.2nb2	# need lrelease
.include "../../x11/qt3-tools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
