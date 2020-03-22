# $NetBSD: Makefile,v 1.62 2020/03/22 10:01:58 nia Exp $

PKGNAME=	${DISTNAME:S/-/-server-/}
COMMENT=	Freeciv game server

DEPENDS+=	freeciv-share>=${FC_VERS}:../../games/freeciv-share

CONFIGURE_ARGS+=	--disable-client
CONFIGURE_ARGS+=	--disable-fcmp
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--with-readline

# Uses rl_filename_completion_function() which was introduced in readline-4.2
BUILDLINK_API_DEPENDS.readline+=	readline>=4.2

.include "../../games/freeciv-share/suppress_installation.mk"
.include "../../games/freeciv-share/Makefile.common"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
