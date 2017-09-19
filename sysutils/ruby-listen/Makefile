# $NetBSD: Makefile,v 1.14 2017/09/19 16:34:55 taca Exp $

DISTNAME=	listen-3.1.5
PKGREVISION=	1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/guard/listen
COMMENT=	Listen to file modifications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rb-fsevent>=0.9.4:../../devel/ruby-rb-fsevent
DEPENDS+=	${RUBY_PKGPREFIX}-rb-inotify>=0.9.7:../../sysutils/ruby-rb-inotify
DEPENDS+=	${RUBY_PKGPREFIX}-dep>=1.2:../../devel/ruby-dep

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
