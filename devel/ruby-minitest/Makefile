# $NetBSD: Makefile,v 1.7 2015/09/13 10:10:54 taca Exp $

DISTNAME=	minitest-5.8.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seattlerb/minitest
COMMENT=	Complete suite of testing facilities for Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-hoe>=3.9:../../devel/hoe
RUBY_RDOC_REQD=	4.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
