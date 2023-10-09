# $NetBSD: Makefile,v 1.3 2023/10/09 04:54:48 pho Exp $

DISTNAME=	attoparsec-iso8601-1.1.0.0
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parsing of ISO 8601 dates, originally from aeson
LICENSE=	modified-bsd

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-base-compat-batteries/buildlink3.mk"
.include "../../time/hs-time-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
