# $NetBSD: Makefile,v 1.7 2002/02/10 11:05:11 skrll Exp $
#

PKGNAME=	prc-tools-gcc-${PRC_TOOLS_VERS}
COMMENT=	gcc for GNU tool chain for Palm cross development

BASE_DIST=	gcc
BASE_VERS=	2.95.2

.include "../../devel/prc-tools/Makefile.common"

DEPENDS+=	prc-tools-binutils>=2.0:../../devel/prc-tools-binutils

ALL_TARGET=	all-gcc
INSTALL_TARGET=	install-gcc

USE_BUILDLINK_ONLY=	YES

#
# Prevent totally unnecessary invocation of autoheader
#
post-patch:
	cd ${WRKDIR}/${BASE_DIST}-${BASE_VERS}/gcc && ${TOUCH} cstamp-h.in

post-install:
	@${RMDIR} ${PREFIX}/m68k-palmos/include

.include "../../mk/bsd.pkg.mk"

# Clear these as the xgcc built during the build phase might not recognize
# any arch-specific options specified.
#
CFLAGS=		# empty
CXXFLAGS=	# empty
CPPFLAGS=	# empty
