# $NetBSD: Makefile,v 1.6 2024/05/02 23:19:38 wiz Exp $

DISTNAME=	crypton-1.0.0
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Cryptography Primitives sink
LICENSE=	modified-bsd

PLIST_SRC+=		PLIST
# Some modules are only built on specific platforms.
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PLIST_SRC+=		PLIST.x86
.endif
PRINT_PLIST_AWK+=	/\/Entropy\/RDRand\./ { next }

.include "../../devel/hs-basement/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
