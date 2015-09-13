# $NetBSD: Makefile,v 1.6 2015/09/13 15:14:46 taca Exp $

DISTNAME=	listen-2.10.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/guard/listen
COMMENT=	Listen to file modifications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-celluloid>=0.15.2:../../devel/ruby-celluloid
#DEPENDS+=	${RUBY_PKGPREFIX}-rb-fsevent>=0.9.3:../../sysutils/ruby-rb-fsevent
DEPENDS+=	${RUBY_PKGPREFIX}-rb-inotify>=0.9:../../sysutils/ruby-rb-inotify

OVERRIDE_GEMSPEC+=	rb-fsevent:

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
