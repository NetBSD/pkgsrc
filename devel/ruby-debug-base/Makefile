# $NetBSD: Makefile,v 1.6 2010/12/04 03:52:25 taca Exp $

DISTNAME=	ruby-debug-base-0.10.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruby-debug/
COMMENT=	Fast implementation of the standard Ruby debugger
LICENSE=	2-clause-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-linecache>=0.3:../../devel/ruby-linecache

RUBY_VERSION_SUPPORTED= 18

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
