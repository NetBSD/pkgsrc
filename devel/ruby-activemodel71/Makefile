# $NetBSD: Makefile,v 1.1 2023/11/30 15:15:26 taca Exp $

DISTNAME=	activemodel-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-activemodel${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit for building modeling frameworks (part of Rails 7.1)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	71
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
