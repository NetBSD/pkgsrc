# $NetBSD: Makefile,v 1.2 2015/09/13 14:24:25 taca Exp $

DISTNAME=	celluloid-essentials-0.20.2.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/celluloid/celluloid-essentials
COMMENT=	Superstructural dependencies of Celluloid
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-bundler>=1.0:../../misc/ruby-bundler
DEPENDS+=	${RUBY_PKGPREFIX}-nenv>=0.2:../../devel/ruby-nenv
DEPENDS+=	${RUBY_PKGPREFIX}-dotenv>=2.0:../../devel/ruby-dotenv
DEPENDS+=	${RUBY_PKGPREFIX}-timers>=4.1.1:../../time/ruby-timers
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-logsplit>=0.1.2:../../devel/ruby-rspec-logsplit

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
