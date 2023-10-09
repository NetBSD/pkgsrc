# $NetBSD: Makefile,v 1.11 2023/10/09 04:54:45 pho Exp $

DISTNAME=	x509-system-1.6.7
PKGREVISION=	6
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Handle per-operating-system X.509 accessors and storage
LICENSE=	modified-bsd

SYSCONFDIR=	/etc

SUBST_CLASSES+=		certs
SUBST_STAGE.certs=	pre-configure
SUBST_FILES.certs=	System/X509/Unix.hs
SUBST_VARS.certs=	SYSCONFDIR

.include "../../security/hs-pem/buildlink3.mk"
.include "../../security/hs-x509/buildlink3.mk"
.include "../../security/hs-x509-store/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
