# $NetBSD: Makefile,v 1.1.1.1 2002/08/04 16:52:45 jdolecek Exp $

DISTNAME=	psi-0.8.6
CATEGORIES=	chat
MASTER_SITES=	http://belnet.dl.sourceforge.net/sourceforge/psi/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@netbsd.org
HOMEPAGE=	http://psi.affinix.com/
COMMENT=	PSI Jabber Client

USE_GMAKE=	yes
USE_X11BASE=	yes

post-patch:
	cd ${WRKSRC}/src && ${SED} -e 's^@PREFIX@^"${PREFIX}"^' common.cpp > common.cpp.new && ${MV} -f common.cpp.new common.cpp

do-build:
	cd ${WRKSRC}/src && [ -f Makefile -a Makefile -nt psi.pro ] || QTDIR='${REAL_QTDIR}' ${REAL_QTDIR}/bin/qmake psi.pro
	cd ${WRKSRC}/src && QTDIR="${REAL_QTDIR}" gmake


do-install:
	cd ${WRKSRC} && PREFIX="${PREFIX}" ./install.sh

BUILDLINK_DEPENDS_METHOD.qt3-tools=	build
# need qt3 3.0.4nb2, for qmake
BUILDLINK_DEPENDS.qt3-tools=		qt3-tools>=3.0.4nb2

.include "../../x11/qt3-libs/buildlink.mk"
.include "../../x11/qt3-tools/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
