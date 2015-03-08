# $NetBSD: Makefile,v 1.12 2015/03/08 16:01:26 taca Exp $

DISTNAME=	rcov-1.0.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/relevance/rcov
COMMENT=	Code coverage analysis for Ruby
LICENSE=	gnu-gpl-v2 OR ruby-license

RUBY_VERSION_SUPPORTED=	18

USE_GCC_RUNTIME=	yes
RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
