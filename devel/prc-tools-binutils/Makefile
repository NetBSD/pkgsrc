# $NetBSD: Makefile,v 1.4 2001/06/27 05:19:10 jlam Exp $
#

PKGNAME=	prc-tools-binutils-${PRC_TOOLS_VERS}
COMMENT=	binutils and host tools for GNU tool chain for Palm cross development

BASE_DIST=	binutils
BASE_VERS=	2.9.1

.include "../../devel/prc-tools/Makefile.common"

USE_BUILDLINK_ONLY=	YES
#USE_LIBINTL=		YES

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
