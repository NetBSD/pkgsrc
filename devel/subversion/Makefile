# $NetBSD: Makefile,v 1.20 2004/03/26 02:27:39 wiz Exp $

PKGNAME=	subversion-${SVNVER}
PKGREVISION=	1
COMMENT=	Version control system, meta-package

DEPENDS+=	subversion-base-${SVNVER}nb1:../../devel/subversion-base
DEPENDS+=	p5-subversion-${SVNVER}nb1:../../devel/p5-subversion
DEPENDS+=	ap2-subversion-${SVNVER}nb1:../../www/ap2-subversion
DEPENDS+=	${PYPKGPREFIX}-subversion-${SVNVER}nb1:../../devel/py-subversion

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
