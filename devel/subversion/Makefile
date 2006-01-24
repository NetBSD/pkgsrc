# $NetBSD: Makefile,v 1.26 2006/01/24 07:32:05 wiz Exp $

PKGNAME=	subversion-${SVNVER}
PKGREVISION=	1
COMMENT=	Version control system, meta-package

DEPENDS+=	subversion-base-${SVNVER}{,nb[0-9]*}:../../devel/subversion-base
DEPENDS+=	p5-subversion-${SVNVER}{,nb[0-9]*}:../../devel/p5-subversion
DEPENDS+=	ap2-subversion-${SVNVER}{,nb[0-9]*}:../../www/ap2-subversion
DEPENDS+=	${PYPKGPREFIX}-subversion-${SVNVER}{,nb[0-9]*}:../../devel/py-subversion
DEPENDS+=	${RUBY_PKGPREFIX}-subversion-${SVNVER}{,nb[0-9]*}:../../devel/ruby-subversion

.include "Makefile.common"

CATEGORIES+=	meta-pkgs

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES
NO_MTREE=	YES

.include "../../lang/python/pyversion.mk"
.include "../../lang/ruby/rubyversion.mk"

# The NO_PATCH macro is gone so we have to do this to prevent the
# patches from being applied:
do-patch:

do-install:

.include "../../mk/bsd.pkg.mk"
