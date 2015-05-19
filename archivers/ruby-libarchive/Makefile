# $NetBSD: Makefile,v 1.6 2015/05/19 13:08:49 ryoon Exp $

DISTNAME=	libarchive-0.1.2
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libarchive.rubyforge.org/
COMMENT=	Ruby bindings for Libarchive
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

# Fix Ruby 2.2 build.
CHECK_WRKREF_SKIP+=	lib/ruby/gems/2.2.0/doc/libarchive-0.1.2/ri/ext/*.ri

.include "../../lang/ruby/gem.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
