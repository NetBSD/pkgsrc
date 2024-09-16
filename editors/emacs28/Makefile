# $NetBSD: Makefile,v 1.29 2024/09/16 07:20:13 adam Exp $

CONFLICTS+=	emacs28-nox11-[0-9]*

PKGREVISION= 22
.include "../../editors/emacs28/Makefile.common"

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
