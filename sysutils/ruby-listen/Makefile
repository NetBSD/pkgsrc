# $NetBSD: Makefile,v 1.10 2016/10/17 14:19:34 taca Exp $

DISTNAME=	listen-3.0.8
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/guard/listen
COMMENT=	Listen to file modifications
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/rubyversion.mk"

.if ${OPSYS} == "Darwin"
DEPENDS+=	${RUBY_PKGPREFIX}-rb-fsevent>=0.9.7:../../devel/ruby-rb-fsevent
OVERRIDE_GEMSPEC+=	rb-inotify:
.else
DEPENDS+=	${RUBY_PKGPREFIX}-rb-inotify>=0.9:../../sysutils/ruby-rb-inotify
OVERRIDE_GEMSPEC+=	rb-fsevent:
.endif
# ruby-listen 3.1.5 require ruby-dep but www/ruby-jekyll-watch require <3.1
#DEPENDS+=	${RUBY_PKGPREFIX}-dep>=1.2:../../devel/ruby-dep

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
