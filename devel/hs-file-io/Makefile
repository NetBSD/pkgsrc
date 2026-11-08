# $NetBSD: Makefile,v 1.5 2026/11/08 17:26:02 pho Exp $

DISTNAME=	file-io-0.2.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Basic file IO operations via 'OsPath'
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	filepath

CONFIGURE_ARGS+=	-f os-string

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
