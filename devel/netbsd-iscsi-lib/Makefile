# $NetBSD: Makefile,v 1.3 2013/04/06 15:46:35 rodent Exp $

PKGNAME=	${DISTNAME:C/-iscsi/-iscsi-lib/}
CATEGORIES=	devel
COMMENT=	NetBSD's iSCSI library (per iSCSI RFC 3720)

BUILD_DIRS+=	src/lib
USE_LIBTOOL=	yes

.include "Makefile.common"

post-install:
	${INSTALL_DATA}	${WRKSRC}/include/iscsi.h ${DESTDIR}${PREFIX}/include
	
.include "../../mk/bsd.pkg.mk"
