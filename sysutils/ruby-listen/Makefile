# $NetBSD: Makefile,v 1.11 2016/10/20 14:55:53 taca Exp $

DISTNAME=	listen-3.1.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/guard/listen
COMMENT=	Listen to file modifications
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable

RUBY_VERSIONS_ACCEPTED= 22 23

.include "../../lang/ruby/rubyversion.mk"

.if ${OPSYS} == "Darwin"
DEPENDS+=	${RUBY_PKGPREFIX}-rb-fsevent>=0.9.4:../../devel/ruby-rb-fsevent
OVERRIDE_GEMSPEC+=	rb-inotify:
.else
DEPENDS+=	${RUBY_PKGPREFIX}-rb-inotify>=0.9.7:../../sysutils/ruby-rb-inotify
OVERRIDE_GEMSPEC+=	rb-fsevent:
.endif
DEPENDS+=	${RUBY_PKGPREFIX}-dep>=1.2:../../devel/ruby-dep

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
