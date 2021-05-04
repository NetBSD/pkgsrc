# $NetBSD: Makefile,v 1.22 2021/05/04 15:30:16 taca Exp $

DISTNAME=	commander-4.6.0
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/commander-rb/commander
COMMENT=	The complete solution for Ruby command-line executables
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-highline>=2.0.0<2.1:../../devel/ruby-highline

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
