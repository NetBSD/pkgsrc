# $NetBSD: Makefile,v 1.3 2002/12/24 06:09:47 wiz Exp $

DISTNAME=	psi-0.8.6
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://belnet.dl.sourceforge.net/sourceforge/psi/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@netbsd.org
HOMEPAGE=	http://psi.affinix.com/
COMMENT=	PSI Jabber Client

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_X11BASE=	yes

BUILD_DIRS=	${WRKSRC}/src

post-patch:
	cd ${WRKSRC}/src && ${SED} -e 's^@PREFIX@^"${PREFIX}"^' common.cpp > common.cpp.new && ${MV} -f common.cpp.new common.cpp

pre-build:
	cd ${WRKSRC}/src;						\
	if [ ! -f Makefile -o Makefile -ot psi.pro ]; then		\
		${SETENV} ${MAKE_ENV} ${QTDIR}/bin/qmake psi.pro;	\
	fi

do-install:
	cd ${WRKSRC} && PREFIX="${PREFIX}" ./install.sh

BUILDLINK_DEPENDS_METHOD.qt3-tools=	build
# need qt3 3.0.4nb2, for qmake
BUILDLINK_DEPENDS.qt3-tools=		qt3-tools>=3.0.4nb2

.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../x11/qt3-tools/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
