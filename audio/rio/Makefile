# $NetBSD: Makefile,v 1.21 2007/06/15 15:13:34 jlam Exp $
#

DISTNAME=	rio007
PKGNAME=	rio-1.07
CATEGORIES=	audio
MASTER_SITES=	http://www.world.co.uk/sba/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.world.co.uk/sba/rio.html
COMMENT=	Utility to display and manage files on the Diamond Rio PMP300

ONLY_FOR_PLATFORM=	NetBSD-*-i386

WRKSRC=		${WRKDIR}/rio107
MAKE_FILE=	makefile
USE_LANGUAGES=	c++
LIBS.NetBSD=	-li386

INSTALLATION_DIRS=	bin
SPECIAL_PERMS=		bin/rio ${SETUID_ROOT_PERMS}

do-build:
	cd ${WRKSRC} && ${CXX} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} ${LIBS} app.cpp rio.cpp -o rio
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/find-lpt-port > ${WRKSRC}/find-lpt-port.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rio ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/rio
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/rio
	${INSTALL_SCRIPT} ${WRKSRC}/find-lpt-port.sh ${PREFIX}/bin/find-lpt-port

.include "../../mk/bsd.pkg.mk"
