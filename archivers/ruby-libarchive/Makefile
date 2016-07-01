# $NetBSD: Makefile,v 1.9 2016/07/01 17:55:23 jperkin Exp $

DISTNAME=	libarchive-0.1.2
PKGREVISION=	1
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/winebarrel/libarchive-ruby
COMMENT=	Ruby bindings for Libarchive
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

.include "../../lang/ruby/gem.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
