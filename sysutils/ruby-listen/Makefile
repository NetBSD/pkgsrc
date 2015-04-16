# $NetBSD: Makefile,v 1.4 2015/04/16 10:53:14 jperkin Exp $

DISTNAME=	listen-2.9.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_RUBYGEMS:=listen/}
COMMENT=	Listen to file modifications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-celluloid>=0.15.2:../../devel/ruby-celluloid
#DEPENDS+=	${RUBY_PKGPREFIX}-rb-fsevent>=0.9.3:../../sysutils/ruby-rb-fsevent
DEPENDS+=	${RUBY_PKGPREFIX}-rb-inotify>=0.9:../../sysutils/ruby-rb-inotify

OVERRIDE_GEMSPEC+=	rb-fsevent:

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
