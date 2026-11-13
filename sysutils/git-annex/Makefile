# $NetBSD: Makefile,v 1.20 2026/11/13 14:39:43 pho Exp $

DISTNAME=	git-annex-10.20261026
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Manage files with git, without checking their contents into git
HOMEPAGE=	https://git-annex.branchable.com/
LICENSE=	gnu-agpl-v3

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

# Don't build git-annex as a dynamic executable. It will depend on like 270
# shared libraries and the dynamic linker will spend 5 seconds each time
# git-annex is invoked. This is unacceptable.
HASKELL_ENABLE_DYNAMIC_EXECUTABLE=	no

.include "options.mk"
.include "../../mk/bsd.fast.prefs.mk"

CONFIGURE_ARGS+=	-f -TastyTap

# Setup dependencies
.include "../../devel/hs-split/buildlink3.mk"
.include "../../sysutils/hs-filepath-bytestring/buildlink3.mk"
.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"

# Mandatory runtime dependencies
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/application.mk"
.include "../../devel/hs-uuid/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../devel/hs-safesemaphore/buildlink3.mk"
.include "../../devel/hs-async/buildlink3.mk"
.include "../../sysutils/hs-disk-free-space/buildlink3.mk"
.include "../../devel/hs-ifelse/buildlink3.mk"
.include "../../devel/hs-monad-logger/buildlink3.mk"
.include "../../math/hs-free/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../converters/hs-sandi/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-bloomfilter/buildlink3.mk"
.include "../../textproc/hs-edit-distance/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-client-tls/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../www/hs-http-conduit/buildlink3.mk"
.include "../../www/hs-http-client-restricted/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../databases/hs-persistent-sqlite/buildlink3.mk"
.include "../../devel/hs-persistent-template/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.include "../../devel/hs-microlens/buildlink3.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../textproc/hs-tagsoup/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../www/hs-feed/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../net/hs-socks/buildlink3.mk"
.include "../../devel/hs-stm-chans/buildlink3.mk"
.include "../../security/hs-crypto-api/buildlink3.mk"
.include "../../devel/hs-split/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-concurrent-output/buildlink3.mk"
.include "../../devel/hs-unbounded-delays/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-tasty/buildlink3.mk"
.include "../../devel/hs-tasty-hunit/buildlink3.mk"
.include "../../devel/hs-tasty-quickcheck/buildlink3.mk"
.include "../../devel/hs-tasty-rerun/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../www/hs-dav/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-bsd/buildlink3.mk"
.include "../../devel/hs-git-lfs/buildlink3.mk"
.include "../../time/hs-clock/buildlink3.mk"
.include "../../www/hs-servant/buildlink3.mk"
.include "../../www/hs-servant-server/buildlink3.mk"
.include "../../www/hs-servant-client/buildlink3.mk"
.include "../../www/hs-servant-client-core/buildlink3.mk"
.include "../../www/hs-warp/buildlink3.mk"
.include "../../www/hs-warp-tls/buildlink3.mk"
.include "../../net/hs-crypton-connection/buildlink3.mk"
.include "../../security/hs-crypton-x509-store/buildlink3.mk"
.include "../../net/hs-aws/buildlink3.mk"
.include "../../devel/hs-persistent/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../security/hs-tls/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../devel/hs-file-io/buildlink3.mk"
.if ${MACHINE_ARCH} != "aarch64" && empty(MACHINE_ARCH:M*arm*)
.  include "../../security/hs-blake3/buildlink3.mk"
.endif
.include "../../net/hs-torrent/buildlink3.mk"
.include "../../misc/hs-magic/buildlink3.mk"
.include "../../benchmarks/hs-criterion/buildlink3.mk"
.if ${OPSYS} == "Linux"
.  include "../../devel/hs-hinotify/buildlink3.mk"
.elif ${OPSYS} == "Darwin"
.  include "../../devel/hs-hfsevents/buildlink3.mk"
.endif
.include "../../net/hs-torrent/buildlink3.mk"
.include "../../misc/hs-magic/buildlink3.mk"
.include "../../benchmarks/hs-criterion/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
