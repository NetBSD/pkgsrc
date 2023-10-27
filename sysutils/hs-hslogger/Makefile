# $NetBSD: Makefile,v 1.6 2023/10/27 19:19:05 pho Exp $

DISTNAME=	hslogger-1.3.1.0
PKGREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Versatile logging framework
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	bytestring	\
	time	\
	unix

.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-bsd/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
