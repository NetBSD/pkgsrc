# $NetBSD: Makefile,v 1.19 2004/03/08 00:06:03 minskim Exp $

PKGNAME=	subversion-${SVNVER}
COMMENT=	Version control system, meta-package

DEPENDS+=	subversion-base-${SVNVER}:../../devel/subversion-base
DEPENDS+=	p5-subversion-${SVNVER}:../../devel/p5-subversion
DEPENDS+=	ap2-subversion-${SVNVER}:../../www/ap2-subversion
DEPENDS+=	${PYPKGPREFIX}-subversion-${SVNVER}:../../devel/py-subversion

.include "Makefile.common"

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_BUILDLINK=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES
NO_MTREE=	YES

.include "../../lang/python/pyversion.mk"

# The NO_PATCH macro is gone so we have to do this to prevent the
# patches from being applied:
do-patch:

do-install:

.include "../../mk/bsd.pkg.mk"
