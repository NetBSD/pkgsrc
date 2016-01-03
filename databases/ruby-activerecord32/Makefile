# $NetBSD: Makefile,v 1.7 2016/01/03 05:11:59 taca Exp $

DISTNAME=	activerecord-${RUBY_RAILS_VERSION}
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Object-relational mapper framework (part of Rails 3.2)
LICENSE=	mit

# Comment out dependency in gemspec but already depends indirectly one.
#DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-arel30>=3.0.2<3.1:../../databases/ruby-arel30
DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo03>=0.3.29<0.4:../../time/ruby-tzinfo03

RUBY_RAILS_SUPPORTED=	32
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
