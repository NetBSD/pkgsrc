# $NetBSD: Makefile,v 1.1.1.1 2010/06/04 16:14:44 sborrill Exp $

PKGNAME=	${DISTNAME:C/-iscsi/-iscsi-lib/}
CATEGORIES=	devel
COMMENT=	NetBSD's iSCSI library (per iSCSI RFC 3720)

BUILD_DIRS+=	${WRKSRC}/src/lib

.include "Makefile.common"

post-install:
	${INSTALL_DATA}	${WRKSRC}/include/iscsi.h ${DESTDIR}${PREFIX}/include
	
.include "../../mk/bsd.pkg.mk"
