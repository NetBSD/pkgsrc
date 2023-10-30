# $NetBSD: Makefile,v 1.10 2023/10/30 17:01:39 pho Exp $

DISTNAME=	hie-bios-0.13.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Set up a GHC API session
LICENSE=	modified-bsd

# hie-bios is built with optparse-applicative, and can generate shell
# completion scripts automatically.
OPTPARSE_APPLICATIVE_EXECUTABLES+=	hie-bios
.include "../../devel/hs-optparse-applicative/application.mk"

# lib:hie-bios
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.include "../../sysutils/hs-co-log-core/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-conduit-extra/buildlink3.mk"
.include "../../security/hs-cryptohash-sha1/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
