# $NetBSD: Makefile,v 1.2 2021/04/11 13:28:02 taca Exp $

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
DEPENDS+=	${RUBY_PKGPREFIX}-marcel>=1.0.0<1.1:../../devel/ruby-marcel
#DEPDENS+=	${RUBY_PKGPREFIX}-mini_mime>=1.0.2<1.1:../../mail/ruby-mini_mime

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	61
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
