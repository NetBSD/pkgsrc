# $NetBSD: Makefile,v 1.24 2024/02/03 15:58:28 taca Exp $

DISTNAME=	commander-5.0.0
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/commander-rb/commander
COMMENT=	The complete solution for Ruby command-line executables
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-highline>=3.0.0:../../devel/ruby-highline

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC+=	highline>=2.0.0
RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
