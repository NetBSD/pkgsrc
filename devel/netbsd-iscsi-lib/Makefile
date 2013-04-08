# $NetBSD: Makefile,v 1.4 2013/04/08 11:17:11 rodent Exp $

PKGNAME=	${DISTNAME:C/-iscsi/-iscsi-lib/}
CATEGORIES=	devel
COMMENT=	NetBSD's iSCSI library (per iSCSI RFC 3720)

BUILD_DIRS+=	src/lib
USE_LIBTOOL=	yes

.include "Makefile.common"

post-install:
	${INSTALL_DATA}	${WRKSRC}/include/iscsi.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
