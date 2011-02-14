# $NetBSD: Makefile,v 1.2.4.1 2011/02/14 19:08:01 spz Exp $

DISTNAME=	activerecord-3.0.4
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Object-relational mapper framework
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=3.0.4<3.0.5:../../devel/ruby-activesupport3
DEPENDS+=	${RUBY_PKGPREFIX}-activemodel>=3.0.4<3.0.5:../../devel/ruby-activemodel
DEPENDS+=	${RUBY_PKGPREFIX}-arel>=2.0.2<2.1:../../databases/ruby-arel
DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo>=0.3.23<0.4:../../time/ruby-tzinfo

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
