# $NetBSD: Makefile,v 1.8 2015/12/13 15:12:04 taca Exp $

DISTNAME=	listen-3.0.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/guard/listen
COMMENT=	Listen to file modifications
LICENSE=	mit

#DEPENDS+=	${RUBY_PKGPREFIX}-rb-fsevent>=0.9.3:../../sysutils/ruby-rb-fsevent
DEPENDS+=	${RUBY_PKGPREFIX}-rb-inotify>=0.9:../../sysutils/ruby-rb-inotify

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	rb-fsevent:

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
