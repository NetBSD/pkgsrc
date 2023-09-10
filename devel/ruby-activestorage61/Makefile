# $NetBSD: Makefile,v 1.6 2023/09/10 14:16:56 taca Exp $

DISTNAME=	activestorage-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-activestorage${RUBY_RAILS}-${RAILS_VERSION}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Local and cloud file storage framework (part of Rails 6.1)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_ACTIVEJOB_DEPENDS}
DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-marcel>=1.0.0<1.1:../../devel/ruby-marcel
DEPENDS+=	${RUBY_PKGPREFIX}-mini_mime>=1.1.0:../../mail/ruby-mini_mime

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	61
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
