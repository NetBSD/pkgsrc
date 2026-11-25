# $NetBSD: Makefile,v 1.80 2026/11/25 17:16:30 wiz Exp $

PKGNAME=	subversion-${SVNVER}
PKGREVISION=	2
COMMENT=	Version control system, meta-package

META_PACKAGE=	yes

.include "../../devel/subversion/Makefile.common"

DEPENDS+=	subversion-base-${SVNVER}{,nb[0-9]*}:../../devel/subversion-base
DEPENDS+=	ap24-subversion-${SVNVER}{,nb[0-9]*}:../../www/ap2-subversion
DEPENDS+=	p5-subversion-${SVNVER}{,nb[0-9]*}:../../devel/p5-subversion
DEPENDS+=	${PYPKGPREFIX}-subversion-${SVNVER}{,nb[0-9]*}:../../devel/py-subversion
DEPENDS+=	${RUBY_PKGPREFIX}-subversion-${SVNVER}{,nb[0-9]*}:../../devel/ruby-subversion

.if !empty(PKG_OPTIONS:Mjava)
# The standard implementation of java is non-portable and non-free, so
# we do not depend on it by default.
DEPENDS+=	java-subversion-${SVNVER}{,nb[0-9]*}:../../devel/java-subversion
.endif

CATEGORIES+=	meta-pkgs

.include "../../lang/python/pyversion.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../www/apache24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
