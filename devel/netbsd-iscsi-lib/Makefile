# $NetBSD: Makefile,v 1.5 2015/10/15 13:15:50 joerg Exp $

PKGNAME=	${DISTNAME:C/-iscsi/-iscsi-lib/}
PKGREVISION=	1
CATEGORIES=	devel
COMMENT=	NetBSD's iSCSI library (per iSCSI RFC 3720)

BUILD_DIRS+=	src/lib
USE_LIBTOOL=	yes

.include "Makefile.common"

post-install:
	${INSTALL_DATA}	${WRKSRC}/include/iscsi.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
