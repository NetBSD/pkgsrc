# $NetBSD: Makefile,v 1.1 2017/04/21 00:12:19 minskim Exp $

DISTNAME=	activerecord-${RUBY_RAILS_VERSION}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Object-relational mapper framework (part of Rails 4.2)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-arel>=6.0:../../databases/ruby-arel

RUBY_RAILS_SUPPORTED=	42
RUBY_RAILS_STRICT_DEP=	yes

OVERRIDE_GEMSPEC+=	arel>=6.0.3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
