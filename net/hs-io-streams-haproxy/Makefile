# $NetBSD: Makefile,v 1.3 2026/11/13 14:39:37 pho Exp $

DISTNAME=	io-streams-haproxy-1.0.1.0
PKGREVISION=	2
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	HAProxy protocol 1.5 support for io-streams
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	attoparsec	\
	base	\
	bytestring	\
	network	\
	transformers

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-io-streams/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
