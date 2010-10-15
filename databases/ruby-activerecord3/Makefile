# $NetBSD: Makefile,v 1.2 2010/10/15 11:43:27 taca Exp $

DISTNAME=	activerecord-3.0.1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Object-relational mapper framework
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=3.0.1:../../devel/ruby-activesupport3
DEPENDS+=	${RUBY_PKGPREFIX}-activemodel>=3.0.1:../../devel/ruby-activemodel
DEPENDS+=	${RUBY_PKGPREFIX}-arel>=1.0.0:../../databases/ruby-arel
DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo>=0.3.23:../../time/ruby-tzinfo

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
