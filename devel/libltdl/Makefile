# $NetBSD: Makefile,v 1.2 2004/11/26 09:39:30 jlam Exp $
#

.include "../../devel/libtool/Makefile.common"

PKGNAME=	${DISTNAME:S/tool-/ltdl-/}
SVR4_PKGNAME=	lltdl

COMMENT=	Generic shared library support (libltdl abstraction library)

CONFLICTS+=	libtool<=1.3.5nb11 libtool-base<=1.5.10nb4

USE_LIBTOOL=	yes

CONFIGURE_ARGS+=--enable-libltdl-install
CONFIGURE_DIRS=	${WRKSRC}/libltdl
BUILD_DIRS=	${WRKSRC}/libltdl

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
