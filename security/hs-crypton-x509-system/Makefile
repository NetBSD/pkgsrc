# $NetBSD: Makefile,v 1.2 2023/11/02 06:37:20 pho Exp $

DISTNAME=	crypton-x509-system-1.6.7
PKGREVISION=	1
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Handle per-operating-system X.509 accessors and storage
LICENSE=	modified-bsd

.include "../../security/hs-crypton-x509/buildlink3.mk"
.include "../../security/hs-crypton-x509-store/buildlink3.mk"
.include "../../security/hs-pem/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
