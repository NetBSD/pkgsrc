# $NetBSD: Makefile,v 1.10 2016/01/06 14:50:34 taca Exp $

DISTNAME=	minitest-5.8.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seattlerb/minitest
COMMENT=	Complete suite of testing facilities for Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-hoe>=3.9:../../devel/hoe
RUBY_RDOC_REQD=	4.0

# ruby23 has the same version.
RUBY_VERSION_SUPPORTED=	200 21 22

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
