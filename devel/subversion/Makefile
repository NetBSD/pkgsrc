# $NetBSD: Makefile,v 1.18 2003/12/06 03:01:57 epg Exp $

PKGNAME=	subversion-${SVNVER}
COMMENT=	Version control system, meta-package

DEPENDS+=	subversion-base-${SVNVER}:../../devel/subversion-base
DEPENDS+=	p5-subversion-${SVNVER}:../../devel/p5-subversion
DEPENDS+=	ap2-subversion-${SVNVER}:../../www/ap2-subversion
# We depend on py-subversion via its buildlink2.mk so we don't
# have to worry about which Python version it uses.

.include "Makefile.common"

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

# The NO_PATCH macro is gone so we have to do this to prevent the
# patches from being applied:
do-patch:

do-install:

.include "../../devel/py-subversion/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
