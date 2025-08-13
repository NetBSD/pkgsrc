# $NetBSD: Makefile,v 1.2 2025/08/13 11:07:12 pho Exp $

DISTNAME=	mbox-0.3.4
PKGREVISION=	1
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Read and write standard mailbox files
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	time

.include "../../devel/hs-safe/buildlink3.mk"
.include "../../time/hs-time-locale-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
