# $NetBSD: Makefile,v 1.8 2015/10/04 12:20:21 taca Exp $

DISTNAME=	minitest-5.8.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seattlerb/minitest
COMMENT=	Complete suite of testing facilities for Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-hoe>=3.9:../../devel/hoe
RUBY_RDOC_REQD=	4.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
