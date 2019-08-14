# $NetBSD: Makefile,v 1.14 2019/08/14 15:45:46 bsiegert Exp $

DISTNAME=	obfs4proxy-0.0.8
PKGREVISION=	5
CATEGORIES=	net security
MASTER_SITES=	https://people.torproject.org/~yawning/releases/obfs4proxy/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	https://people.torproject.org/~yawning/releases/obfs4proxy/
COMMENT=	Look-like nothing obfuscation protocol
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	obfs4
GO_SRCPATH=	gitlab.com/yawning/obfs4.git

.include "../../devel/go-ed25519/buildlink3.mk"
.include "../../devel/go-goptlib/buildlink3.mk"
.include "../../devel/go-siphash/buildlink3.mk"
.include "../../net/go-net/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
