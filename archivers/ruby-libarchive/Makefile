# $NetBSD: Makefile,v 1.7 2015/09/25 05:45:58 taca Exp $

DISTNAME=	libarchive-0.1.2
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/winebarrel/libarchive-ruby
COMMENT=	Ruby bindings for Libarchive
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

# Fix Ruby 2.2 build.
CHECK_WRKREF_SKIP+=	lib/ruby/gems/2.2.0/doc/libarchive-0.1.2/ri/ext/*.ri

.include "../../lang/ruby/gem.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
