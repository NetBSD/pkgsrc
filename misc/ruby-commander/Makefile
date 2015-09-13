# $NetBSD: Makefile,v 1.13 2015/09/13 14:42:34 taca Exp $

DISTNAME=	commander-4.3.5
CATEGORIES=	misc

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://ramaze.net/
COMMENT=	The complete solution for Ruby command-line executables
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.7.2<1.8:../../devel/ruby-highline

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
