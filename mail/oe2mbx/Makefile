# $NetBSD: Makefile,v 1.8 2005/12/05 20:50:34 rillig Exp $
#

DISTNAME=	oe2mbx-1.21
CATEGORIES=	mail
MASTER_SITES=	http://www.gpl.no/liboe/download/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.gpl.no/liboe/
COMMENT=	Outlook Express messages to the Unix mailbox format converter

WRKSRC=		${WRKDIR}/liboe-0.92
MAKEFILE=	makefile

MAKE_ENV+=      INSTALL_PROGRAM=${INSTALL_PROGRAM:Q} \
		INSTALL_LIB=${INSTALL_LIB:Q} \
		INSTALL_DATA=${INSTALL_DATA:Q}

BUILD_TARGET=	liboe oe2mbx
INSTALLATION_DIRS=	bin lib include

pre-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} clean

.include "../../mk/bsd.pkg.mk"
