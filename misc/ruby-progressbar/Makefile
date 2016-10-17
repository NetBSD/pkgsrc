# $NetBSD: Makefile,v 1.14 2016/10/17 14:27:37 taca Exp $

DISTNAME=	ruby-progressbar-1.8.1
PKGNAME=	${DISTNAME:S/ruby-/${RUBY_PKGPREFIX}-/}
CATEGORIES=	misc ruby

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jfelchner/ruby-progressbar
COMMENT=	Text Progress Bar Library for Ruby
LICENSE=	mit

RUBY_VERSIONS_ACCEPTED=	18 21 22 23

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
