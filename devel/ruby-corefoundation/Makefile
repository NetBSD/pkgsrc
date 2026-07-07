# $NetBSD: Makefile,v 1.2 2026/07/07 13:59:30 taca Exp $

DISTNAME=	corefoundation-0.3.19
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/corefoundation
COMMENT=	Ruby wrapper for macOS Core Foundation framework
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.15.0:../../devel/ruby-ffi

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
