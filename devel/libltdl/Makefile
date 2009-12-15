# $NetBSD: Makefile,v 1.4 2009/12/15 17:07:43 joerg Exp $
#

.include "../../devel/libtool/Makefile.common"

PKGNAME=	${DISTNAME:S/tool-/ltdl-/}
PKGREVISION=	1
SVR4_PKGNAME=	lltdl

COMMENT=	Generic shared library support (libltdl abstraction library)

CONFLICTS+=	libtool<=1.3.5nb11 libtool-base<=1.5.10nb4

USE_LIBTOOL=	yes

CONFIGURE_ARGS+=--enable-libltdl-install
BUILD_DIRS=	${WRKSRC}/libltdl

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
