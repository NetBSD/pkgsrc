# $NetBSD: Makefile,v 1.4 2001/06/27 05:17:41 jlam Exp $
#

PKGNAME=	prc-tools-gcc-${PRC_TOOLS_VERS}
COMMENT=	gcc for GNU tool chain for Palm cross development

BASE_DIST=	gcc
BASE_VERS=	2.95.2

.include "../../devel/prc-tools/Makefile.common"

BUILD_DEPENDS+=	autoconf-*:../../devel/autoconf
DEPENDS+=	prc-tools-binutils>=2.0:../../devel/prc-tools-binutils

ALL_TARGET=	all-gcc
INSTALL_TARGET=	install-gcc

post-install:
	@${RMDIR} ${PREFIX}/m68k-palmos/include

.include "../../mk/bsd.pkg.mk"
