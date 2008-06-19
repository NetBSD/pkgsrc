# $NetBSD: Makefile,v 1.34 2008/06/19 22:33:25 epg Exp $

PKGNAME=	subversion-${SVNVER}
COMMENT=	Version control system, meta-package

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/subversion/Makefile.common"

DEPENDS+=	subversion-base-${SVNVER}{,nb[0-9]*}:../../devel/subversion-base
DEPENDS+=	${APACHE_PKG_PREFIX}-subversion-${SVNVER}{,nb[0-9]*}:../../www/ap2-subversion
DEPENDS+=	java-subversion-${SVNVER}{,nb[0-9]*}:../../devel/java-subversion
DEPENDS+=	p5-subversion-${SVNVER}{,nb[0-9]*}:../../devel/p5-subversion
DEPENDS+=	${PYPKGPREFIX}-subversion-${SVNVER}{,nb[0-9]*}:../../devel/py-subversion
DEPENDS+=	${RUBY_PKGPREFIX}-subversion-${SVNVER}{,nb[0-9]*}:../../devel/ruby-subversion


CATEGORIES+=	meta-pkgs

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES
PLIST_SRC=	# empty (meta-package)

.include "../../lang/python/pyversion.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/apache.mk"

# The NO_PATCH macro is gone so we have to do this to prevent the
# patches from being applied:
do-patch:

do-install:

.include "../../mk/bsd.pkg.mk"
