# $NetBSD: Makefile,v 1.1.1.1 2013/04/10 09:21:51 tonnerre Exp $

DISTNAME=	minitest-4.7.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seattlerb/minitest
COMMENT=	Complete suite of testing facilities for Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-rdoc>=3.10:../../devel/ruby-rdoc
DEPENDS+=	${RUBY_PKGPREFIX}-hoe>=3.5:../../devel/hoe
CONFLICTS+=	ruby[1-9][0-9][0-9]-minitest-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
