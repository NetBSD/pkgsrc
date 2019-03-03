# $NetBSD: Makefile,v 1.1 2019/03/03 14:45:53 taca Exp $

DISTNAME=	activemodel-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-activemodel${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit for building modeling frameworks (part of Rails 5.2)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	52
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
