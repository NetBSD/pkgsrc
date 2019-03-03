# $NetBSD: Makefile,v 1.1 2019/03/03 14:55:02 taca Exp $

DISTNAME=	activerecord-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-activerecord${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Object-relational mapper framework (part of Rails 5.2)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-arel>=9.0:../../databases/ruby-arel

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	52
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
