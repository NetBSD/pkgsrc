# $NetBSD: Makefile,v 1.10 2026/02/06 10:04:38 wiz Exp $

CONFLICTS+=	emacs30-nox11-[0-9]*

PKGREVISION= 6
.include "../../editors/emacs30/Makefile.common"

.include "options.mk"

# Erroneously tries to enable inotify by default.
.if ${OPSYS} == "SunOS"
.  include "../../devel/glib2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-file-notification=gfile
.endif

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
