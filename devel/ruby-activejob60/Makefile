# $NetBSD: Makefile,v 1.2 2020/03/21 23:51:40 joerg Exp $

DISTNAME=	activejob-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-activejob${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Job classes that can be run by a variety of queueing backends
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-globalid>=0.3.6:../../devel/ruby-globalid

USE_LANGUAGES=	# none

RUBY_VERSIONS_INCOMPATIBLE=	24
RUBY_RAILS_ACCEPTED=	60
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
