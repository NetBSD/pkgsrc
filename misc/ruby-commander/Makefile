# $NetBSD: Makefile,v 1.23 2023/04/30 14:43:15 taca Exp $

DISTNAME=	commander-4.6.0
PKGREVISION=	1
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/commander-rb/commander
COMMENT=	The complete solution for Ruby command-line executables
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-highline>=2.0.0:../../devel/ruby-highline

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC+=	highline>=2.0.0
RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
