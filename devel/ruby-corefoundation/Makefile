# $NetBSD: Makefile,v 1.1 2022/11/29 12:42:00 taca Exp $

DISTNAME=	corefoundation-0.3.13
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/corefoundation
COMMENT=	Ruby wrapper for macOS Core Foundation framework
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.15.0:../../devel/ruby-ffi

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
