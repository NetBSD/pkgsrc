# $NetBSD: Makefile,v 1.13 2016/09/08 15:19:17 joerg Exp $

DISTNAME=	rcov-1.0.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/relevance/rcov
COMMENT=	Code coverage analysis for Ruby
LICENSE=	gnu-gpl-v2 OR ruby-license

RUBY_VERSIONS_ACCEPTED=	18

USE_GCC_RUNTIME=	yes
RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
