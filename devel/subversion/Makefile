# $NetBSD: Makefile,v 1.11 2003/05/25 09:31:28 epg Exp $

PKGNAME=	subversion-${SVNVER}
COMMENT=	Version control system, meta-package

DEPENDS+=	subversion-base-${SVNVER}:../../devel/subversion-base
DEPENDS+=	ap2-subversion-${SVNVER}:../../www/ap2-subversion
# We depend on subversion-python via its buildlink2.mk so we don't
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

.include "../../devel/subversion-python/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
