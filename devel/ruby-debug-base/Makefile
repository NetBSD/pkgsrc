# $NetBSD: Makefile,v 1.7 2011/02/21 16:01:13 taca Exp $

DISTNAME=	ruby-debug-base-0.10.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruby-debug/
COMMENT=	Fast implementation of the standard Ruby debugger
LICENSE=	2-clause-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-linecache>=0.3:../../devel/ruby-linecache

RUBY_VERSION_SUPPORTED= 18

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
