# $NetBSD: Makefile,v 1.6.2.1 2011/02/27 00:26:15 tron Exp $

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
