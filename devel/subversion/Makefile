# $NetBSD: Makefile,v 1.31 2007/07/03 12:51:20 joerg Exp $

PKGNAME=	subversion-${SVNVER}
COMMENT=	Version control system, meta-package

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/subversion/Makefile.common"

DEPENDS+=	subversion-base-${SVNVER}{,nb[0-9]*}:../../devel/subversion-base
DEPENDS+=	p5-subversion-${SVNVER}{,nb[0-9]*}:../../devel/p5-subversion
.if !empty(PKG_OPTIONS:Mapache22)
DEPENDS+=	ap22-subversion-${SVNVER}{,nb[0-9]*}:../../www/ap2-subversion
.else
DEPENDS+=	ap2-subversion-${SVNVER}{,nb[0-9]*}:../../www/ap2-subversion
.endif
DEPENDS+=	${PYPKGPREFIX}-subversion-${SVNVER}{,nb[0-9]*}:../../devel/py-subversion
DEPENDS+=	${RUBY_PKGPREFIX}-subversion-${SVNVER}{,nb[0-9]*}:../../devel/ruby-subversion


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
