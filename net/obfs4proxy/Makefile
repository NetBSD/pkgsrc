# $NetBSD: Makefile,v 1.68 2024/04/05 19:14:04 bsiegert Exp $

DISTNAME=	obfs4proxy-0.0.11
PKGREVISION=	31
CATEGORIES=	net security
MASTER_SITES=	https://people.torproject.org/~yawning/releases/obfs4proxy/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://people.torproject.org/~yawning/releases/obfs4proxy/
COMMENT=	Look-like nothing obfuscation protocol
LICENSE=	modified-bsd

GO_BUILD_PATTERN= ./obfs4proxy
WRKSRC=		${WRKDIR}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
