# $NetBSD: Makefile,v 1.5 2001/06/28 05:48:19 jlam Exp $
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

USE_BUILDLINK_ONLY=	YES

post-install:
	@${RMDIR} ${PREFIX}/m68k-palmos/include

.include "../../mk/bsd.pkg.mk"

# Clear these as the xgcc built during the build phase might not recognize
# any arch-specific options specified.
#
CFLAGS=		# empty
CXXFLAGS=	# empty
CPPFLAGS=	# empty
