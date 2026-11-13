# $NetBSD: Makefile,v 1.19 2026/11/13 14:39:55 pho Exp $

DISTNAME=	regex-posix-0.96.0.1
PKGREVISION=	10
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	POSIX Backend for "Text.Regex" (regex-base)
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	bytestring	\
	containers

.include "../../mk/haskell.mk"
.include "../../textproc/hs-regex-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
