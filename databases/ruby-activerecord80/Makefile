# $NetBSD: Makefile,v 1.2 2025/01/23 08:02:12 wiz Exp $

DISTNAME=	activerecord-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-activerecord${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Object-relational mapper framework (part of Rails 8.0)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	80
RUBY_RAILS_STRICT_DEP=	yes

RUBY_VERSIONS_INCOMPATIBLE=	31

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} < 33
DEPENDS+=	${RUBY_PKGPREFIX}-timeout>=0.4.0:../../time/ruby-timeout
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
