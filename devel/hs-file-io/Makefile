# $NetBSD: Makefile,v 1.6 2026/11/13 14:38:57 pho Exp $

DISTNAME=	file-io-0.2.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Basic file IO operations via 'OsPath'
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	filepath

CONFIGURE_ARGS+=	-f os-string

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
