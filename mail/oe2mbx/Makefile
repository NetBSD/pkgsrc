# $NetBSD: Makefile,v 1.6 2005/02/05 16:27:39 zuntum Exp $
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

pre-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} clean

.include "../../mk/bsd.pkg.mk"
