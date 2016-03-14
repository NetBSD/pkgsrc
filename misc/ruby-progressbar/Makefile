# $NetBSD: Makefile,v 1.12 2016/03/14 00:59:06 tnn Exp $

DISTNAME=	ruby-progressbar-1.7.5
PKGNAME=	${DISTNAME:S/ruby-/${RUBY_PKGPREFIX}-/}
CATEGORIES=	misc ruby

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jfelchner/ruby-progressbar
COMMENT=	Text Progress Bar Library for Ruby
LICENSE=	mit

RUBY_VERSION_SUPPORTED=	18 21 22 23

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
