# $NetBSD: Makefile,v 1.3 2023/11/02 06:37:20 pho Exp $

DISTNAME=	crypton-0.33
PKGREVISION=	1
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Cryptography Primitives sink
LICENSE=	modified-bsd

# Some modules are only built on specific platforms.
PLIST_VARS+=		x86
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PLIST.x86=		yes
.endif
PRINT_PLIST_AWK+=	/\/Entropy\/RDRand\./ { $$0 = "$${PLIST.x86}" $$0 }

.include "../../devel/hs-basement/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
