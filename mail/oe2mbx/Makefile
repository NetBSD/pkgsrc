# $NetBSD: Makefile,v 1.7 2005/04/01 03:00:17 reed Exp $
#

DISTNAME=	oe2mbx-1.21
CATEGORIES=	mail
MASTER_SITES=	http://www.gpl.no/liboe/download/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.gpl.no/liboe/
COMMENT=	Outlook Express messages to the Unix mailbox format converter

WRKSRC=		${WRKDIR}/liboe-0.92
MAKEFILE=	makefile

MAKE_ENV+=      INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_LIB="${INSTALL_LIB}" \
		INSTALL_DATA="${INSTALL_DATA}"

BUILD_TARGET=	liboe oe2mbx
INSTALLATION_DIRS=	bin lib include

pre-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} clean

.include "../../mk/bsd.pkg.mk"
