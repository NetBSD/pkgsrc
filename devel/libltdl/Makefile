# $NetBSD: Makefile,v 1.7 2019/11/03 10:39:17 rillig Exp $
#

.include "../../devel/libtool/Makefile.common"

PKGNAME=	${DISTNAME:S/tool-/ltdl-/}

COMMENT=	Generic shared library support (libltdl abstraction library)

CONFLICTS+=	libtool<=1.3.5nb11 libtool-base<=1.5.10nb4

USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--enable-ltdl-install

CONFIGURE_DIRS=	libltdl

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
