# $NetBSD: Makefile,v 1.3 2017/07/18 14:35:48 taca Exp $

DISTNAME=	activerecord-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-activerecord${RUBY_RAILS}-${RAILS_VERSION}
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Object-relational mapper framework (part of Rails 4.2)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-arel60>=6.0<7:../../databases/ruby-arel60

RUBY_RAILS_SUPPORTED=	42
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
