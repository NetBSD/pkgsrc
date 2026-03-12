# $NetBSD: Makefile,v 1.8 2026/03/12 15:37:52 taca Exp $

DISTNAME=	zlib-3.2.3
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/zlib
COMMENT=	Ruby interface for the zlib library
LICENSE=	2-clause-bsd OR ruby-license

# Ruby 3.4.9 contains the same version as bundled gem
RUBY_VERSIONS_ACCEPTED=	32 33 40

.include "../../lang/ruby/gem.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
