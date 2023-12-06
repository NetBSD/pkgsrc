# $NetBSD: Makefile,v 1.61.2.2 2023/12/06 12:08:47 spz Exp $

DISTNAME=	obfs4proxy-0.0.11
PKGREVISION=	26
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
