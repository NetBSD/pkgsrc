# $NetBSD: Makefile,v 1.3 2022/10/10 03:36:48 taca Exp $

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

RUBY_RAILS_ACCEPTED=	70
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
