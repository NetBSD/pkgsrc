# $NetBSD: Makefile,v 1.3 2013/05/31 12:40:57 wiz Exp $

PKGNAME=	subversion16-${SVNVER}
PKGREVISION=	1
COMMENT=	Version control system, meta-package

META_PACKAGE=	# empty

.include "../../devel/subversion16/Makefile.common"

DEPENDS+=	subversion16-base-${SVNVER}{,nb[0-9]*}:../../devel/subversion16-base
#DEPENDS+=	${APACHE_PKG_PREFIX}-subversion16-${SVNVER}{,nb[0-9]*}:../../www/ap2-subversion16
#DEPENDS+=	p5-subversion16-${SVNVER}{,nb[0-9]*}:../../devel/p5-subversion16
#DEPENDS+=	${PYPKGPREFIX}-subversion16-${SVNVER}{,nb[0-9]*}:../../devel/py-subversion16
#DEPENDS+=	${RUBY_PKGPREFIX}-subversion16-${SVNVER}{,nb[0-9]*}:../../devel/ruby-subversion16

#.if !empty(PKG_OPTIONS:Mjava)
# The standard implementation of java is non-portable and non-free, so
# we do not depend on it by default.
#DEPENDS+=	java-subversion16-${SVNVER}{,nb[0-9]*}:../../devel/java-subversion16
#.endif

CATEGORIES+=	meta-pkgs

.include "../../lang/python/pyversion.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/apache.mk"

.include "../../mk/bsd.pkg.mk"
