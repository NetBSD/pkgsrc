# $NetBSD: Makefile,v 1.9 2008/03/05 17:14:10 jlam Exp $

DISTNAME=	mtscan-20050129
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mail-index.NetBSD.org/port-i386/2005/01/29/0011.html
COMMENT=	Magtape scanner - reports record and file-mark structure

NOT_FOR_PLATFORM=	Interix-*-* # no local tape ioctls

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CHECKSUM=	yes

INSTALLATION_DIRS=	bin

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} -O2 -DMTIO -o mtscan mtscan.c -ltermcap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtscan ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
