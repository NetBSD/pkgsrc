# $NetBSD: Makefile,v 1.9 2016/03/15 15:35:52 taca Exp $

DISTNAME=	listen-3.0.6
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

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
