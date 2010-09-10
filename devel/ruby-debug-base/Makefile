# $NetBSD: Makefile,v 1.5 2010/09/10 05:17:36 taca Exp $

DISTNAME=	ruby-debug-base-0.10.3
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
