# $NetBSD: Makefile,v 1.4 2002/02/18 15:14:14 seb Exp $
#

.include "../../devel/prc-tools/Makefile.common"

PKGNAME=	prc-tools-base-${PRC_TOOLS_VERS}
COMMENT=	object files and documentation for GNU tool chain for Palm cross development

DEPENDS+=	prc-tools-gcc>=2.0:../../devel/prc-tools-gcc
DEPENDS+=	palmos-includes>=3.5.1:../../devel/palmos-includes

USE_BUILDLINK_ONLY=	YES
TEXINFO_OVERRIDE=	YES

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
