# $NetBSD: Makefile,v 1.26 2017/09/04 18:00:49 wiz Exp $
#

DISTNAME=	rio007
PKGNAME=	rio-1.07
CATEGORIES=	audio
MASTER_SITES=	http://www.world.co.uk/sba/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.world.co.uk/sba/rio.html
COMMENT=	Utility to display and manage files on the Diamond Rio PMP300
LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64

WRKSRC=		${WRKDIR}/rio107
MAKE_FILE=	makefile
USE_LANGUAGES=	c++
LIBS.NetBSD=	-l$(MACHINE_ARCH)

INSTALLATION_DIRS=	bin
SPECIAL_PERMS=		bin/rio ${SETUID_ROOT_PERMS}

do-build:
	cd ${WRKSRC} && ${CXX} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} ${LIBS} app.cpp rio.cpp -o rio
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/find-lpt-port > ${WRKSRC}/find-lpt-port.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rio ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/rio
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/rio
	${INSTALL_SCRIPT} ${WRKSRC}/find-lpt-port.sh \
		${DESTDIR}${PREFIX}/bin/find-lpt-port

.include "../../mk/bsd.pkg.mk"
