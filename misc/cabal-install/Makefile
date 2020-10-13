# $NetBSD: Makefile,v 1.2 2020/10/13 12:08:10 pho Exp $

DISTNAME=	cabal-install-3.0.0.0
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	misc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Command-line interface for Cabal and Hackage
LICENSE=	modified-bsd

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-configure
SUBST_MESSAGE.mandir=	Fixing man page installation path
SUBST_FILES.mandir+=	Setup.hs
SUBST_VARS.mandir+=	PKGMANDIR

.include "../../devel/hs-async/buildlink3.mk"
.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.include "../../security/hs-cryptohash-sha256/buildlink3.mk"
.include "../../devel/hs-echo/buildlink3.mk"
.include "../../textproc/hs-edit-distance/buildlink3.mk"
.include "../../security/hs-hackage-security/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../www/hs-HTTP/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../archivers/hs-tar/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../net/hs-resolv/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
