# $NetBSD: Makefile,v 1.13 2024/04/29 04:31:09 pho Exp $

DISTNAME=	regex-posix-0.96.0.1
PKGREVISION=	5
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	POSIX Backend for "Text.Regex" (regex-base)
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	bytestring

.include "../../mk/haskell.mk"
.include "../../textproc/hs-regex-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
