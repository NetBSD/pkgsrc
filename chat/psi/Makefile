# $NetBSD: Makefile,v 1.7 2003/05/02 11:54:06 wiz Exp $

DISTNAME=	psi-0.8.7
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://belnet.dl.sourceforge.net/sourceforge/psi/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@netbsd.org
HOMEPAGE=	http://psi.affinix.com/
COMMENT=	PSI Jabber Client

# need qt3 3.0.4nb2, for qmake
BUILD_DEPENDS+=	qt3-tools>=3.0.4nb2:../../x11/qt3-tools

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_X11BASE=	yes
HAS_CONFIGURE=	yes

BUILD_DIRS=	${WRKSRC}/src

CONFIGURE_ARGS+= -p ${PREFIX}

post-configure:
	${SED} -e 's:^CHK_DIR_EXISTS *= *$$:CHK_DIR_EXISTS=test -d:' -e "s:^MKDIR *= *$$:MKDIR=${MKDIR}:" -e "s:/bin/true:${TRUE}:" < ${BUILD_DIRS}/Makefile > ${BUILD_DIRS}/Makefile.orig
	${MV} ${BUILD_DIRS}/Makefile.orig ${BUILD_DIRS}/Makefile

# This order is needed to pickup any freetype version dependencies from qt3
.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
