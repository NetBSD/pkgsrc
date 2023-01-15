# $NetBSD: Makefile,v 1.22 2023/01/15 15:44:37 taca Exp $

DISTNAME=	listen-3.8.0
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/guard/listen
COMMENT=	Listen to file modifications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rb-fsevent>=0.10.3:../../devel/ruby-rb-fsevent
DEPENDS+=	${RUBY_PKGPREFIX}-rb-inotify>=0.9.10:../../devel/ruby-rb-inotify

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
