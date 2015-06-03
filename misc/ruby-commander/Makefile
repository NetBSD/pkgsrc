# $NetBSD: Makefile,v 1.12 2015/06/03 13:55:24 taca Exp $

DISTNAME=	commander-4.3.4
CATEGORIES=	misc

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://ramaze.net/
COMMENT=	The complete solution for Ruby command-line executables
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.7.2<1.8:../../devel/ruby-highline

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
