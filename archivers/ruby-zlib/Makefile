# $NetBSD: Makefile,v 1.9 2026/03/22 13:21:38 taca Exp $

DISTNAME=	zlib-3.2.3
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/zlib
COMMENT=	Ruby interface for the zlib library
LICENSE=	2-clause-bsd OR ruby-license

# Ruby 3.4.9 and 4.0.2 contains the same version as bundled gem
RUBY_VERSIONS_ACCEPTED=	32 33

.include "../../lang/ruby/gem.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
