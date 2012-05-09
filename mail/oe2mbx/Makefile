# $NetBSD: Makefile,v 1.12.18.1 2012/05/09 06:26:08 tron Exp $
#

DISTNAME=	oe2mbx-1.21
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://web.archive.org/2/www.gpl.no/liboe/
COMMENT=	Outlook Express messages to the Unix mailbox format converter

PKG_DESTDIR_SUPPORT=	user-destdir

# assumes fpos_t is an integral type
NOT_FOR_PLATFORM=	Linux-*-*

WRKSRC=		${WRKDIR}/liboe-0.92
MAKE_FILE=	makefile

MAKE_ENV+=	INSTALL_PROGRAM=${INSTALL_PROGRAM:Q} \
		INSTALL_LIB=${INSTALL_LIB:Q} \
		INSTALL_DATA=${INSTALL_DATA:Q}

BUILD_TARGET=	liboe oe2mbx
INSTALLATION_DIRS=	bin lib include

pre-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} clean

.include "../../mk/bsd.pkg.mk"
