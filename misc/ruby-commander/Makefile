# $NetBSD: Makefile,v 1.20 2018/09/23 15:46:43 taca Exp $

DISTNAME=	commander-4.4.6
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ramaze.net/
COMMENT=	The complete solution for Ruby command-line executables
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-highline17>=1.7.2<1.8:../../devel/ruby-highline17

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
