# $NetBSD: Makefile,v 1.11 2026/02/06 08:34:37 wiz Exp $

DISTNAME=	libarchive-0.1.2
PKGREVISION=	2
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://bitbucket.org/winebarrel/libarchive-ruby
COMMENT=	Ruby bindings for Libarchive
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

.include "../../lang/ruby/gem.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
