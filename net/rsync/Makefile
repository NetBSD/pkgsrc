# $NetBSD: Makefile,v 1.138 2026/11/06 11:52:39 wiz Exp $

.include "Makefile.common"

PKGREVISION=	1

COMMENT=	Network file distribution/synchronisation utility

USE_TOOLS+=		bash:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-rsyncd-conf=${PKG_SYSCONFDIR}/rsyncd.conf
CONFIGURE_ARGS+=	--with-included-zlib=no
PKG_SYSCONFSUBDIR=	rsync
TEST_TARGET=		test

REPLACE_BASH=		rsync-ssl

RCD_SCRIPTS=		rsyncd
RCD_SCRIPT_SRC.rsyncd=	files/rsyncd.sh
SMF_NAME=		rsyncd

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	rsync.1 rsyncd.conf.5
SUBST_SED.paths=	-e 's|/etc/rsyncd|${PKG_SYSCONFDIR}/rsyncd|g'
SUBST_SED.paths+=	-e 's|/usr/bin/rsync|${PREFIX}/bin/rsync|g'

# test status as of 3.5.2
# 242 passed
# 6 failed
# 129 skipped

.include "options.mk"

.include "../../archivers/lz4/buildlink3.mk"
# needed for testing
#.include "../../lang/python/tool.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libidn2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/xxhash/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
