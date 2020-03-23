# $NetBSD: Makefile,v 1.21 2020/03/23 16:37:11 taca Exp $

DISTNAME=	commander-4.5.2
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
