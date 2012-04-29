# $NetBSD: Makefile,v 1.2 2012/04/29 12:58:23 taca Exp $

DISTNAME=	activerecord-${RUBY_RAILS_VERSION}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Object-relational mapper framework (part of Rails 3.2)
LICENSE=	mit

# Comment out dependency in gemspec but already depends indirectly one.
#DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-arel>=3.0.2<3.1:../../databases/ruby-arel
DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo>=0.3.29<0.4:../../time/ruby-tzinfo

RUBY_RAILS_SUPPORTED=	32

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
