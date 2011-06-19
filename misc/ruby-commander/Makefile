# $NetBSD: Makefile,v 1.2 2011/06/19 01:47:47 taca Exp $

DISTNAME=	commander-4.0.4
CATEGORIES=	misc

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://ramaze.net/
COMMENT=	The complete solution for Ruby command-line executables
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.5.0:../../devel/ruby-highline

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
