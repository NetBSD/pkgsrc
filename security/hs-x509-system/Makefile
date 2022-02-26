# $NetBSD: Makefile,v 1.6 2022/02/26 03:58:22 pho Exp $

DISTNAME=	x509-system-1.6.7
PKGREVISION=	2
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Handle per-operating-system X.509 accessors and storage
LICENSE=	modified-bsd

.include "../../security/hs-pem/buildlink3.mk"
.include "../../security/hs-x509/buildlink3.mk"
.include "../../security/hs-x509-store/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
