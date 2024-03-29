# $NetBSD: Makefile,v 1.14 2023/11/02 06:37:15 pho Exp $

DISTNAME=	cabal-install-3.10.1.0
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	misc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Command-line interface for Cabal and Hackage
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	resolv

INSTALLATION_DIRS+=	share/bash-completion/completions
post-install:
	${INSTALL_DATA} ${WRKSRC}/bash-completion/cabal \
		${DESTDIR}${PREFIX}/share/bash-completion/completions

.include "../../devel/hs-async/buildlink3.mk"
.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.include "../../misc/hs-cabal-install-solver/buildlink3.mk"
.include "../../security/hs-cryptohash-sha256/buildlink3.mk"
.include "../../devel/hs-echo/buildlink3.mk"
.include "../../textproc/hs-edit-distance/buildlink3.mk"
.include "../../security/hs-hackage-security/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../www/hs-HTTP/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../textproc/hs-regex-base/buildlink3.mk"
.include "../../textproc/hs-regex-posix/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.include "../../archivers/hs-tar/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../net/hs-resolv/buildlink3.mk"
.include "../../devel/hs-lukko/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
