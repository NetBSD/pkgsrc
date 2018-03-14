# $NetBSD: Makefile,v 1.17 2018/03/14 14:54:32 taca Exp $

DISTNAME=	commander-4.4.4
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ramaze.net/
COMMENT=	The complete solution for Ruby command-line executables
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.7.2<1.8:../../devel/ruby-highline

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
