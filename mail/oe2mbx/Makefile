# $NetBSD: Makefile,v 1.19 2022/12/07 15:04:55 wiz Exp $

DISTNAME=	oe2mbx-1.21
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://web.archive.org/2/www.gpl.no/liboe/
COMMENT=	Outlook Express messages to the Unix mailbox format converter

# assumes fpos_t is an integral type
BROKEN_ON_PLATFORM=	Linux-*-*

WRKSRC=		${WRKDIR}/liboe-0.92
MAKE_FILE=	makefile

MAKE_ENV+=	INSTALL_PROGRAM=${INSTALL_PROGRAM:Q} \
		INSTALL_LIB=${INSTALL_LIB:Q} \
		INSTALL_DATA=${INSTALL_DATA:Q}

BUILD_TARGET=		liboe oe2mbx
INSTALLATION_DIRS=	bin lib include

pre-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} clean

.include "../../mk/bsd.pkg.mk"
