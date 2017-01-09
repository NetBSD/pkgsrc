# $NetBSD: Makefile,v 1.12 2017/01/09 15:02:31 taca Exp $

DISTNAME=	listen-3.1.5
PKGREVISION=	1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/guard/listen
COMMENT=	Listen to file modifications
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable

RUBY_VERSIONS_ACCEPTED= 22 23

.include "../../lang/ruby/rubyversion.mk"

DEPENDS+=	${RUBY_PKGPREFIX}-rb-fsevent>=0.9.4:../../devel/ruby-rb-fsevent
DEPENDS+=	${RUBY_PKGPREFIX}-rb-inotify>=0.9.7:../../sysutils/ruby-rb-inotify
DEPENDS+=	${RUBY_PKGPREFIX}-dep>=1.2:../../devel/ruby-dep

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
