# $NetBSD: Makefile,v 1.1 2020/03/20 17:08:50 taca Exp $

DISTNAME=	activestorage-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-activestorage${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Local and cloud file storage framework (part of Rails 6.0)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_ACTIVEJOB_DEPENDS}
DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-marcel>=0.3.1<0.4:../../devel/ruby-marcel

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	60
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
