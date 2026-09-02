# $NetBSD: Makefile,v 1.3 2026/09/02 19:01:48 wiz Exp $

CONFLICTS+=	emacs31-nox11-[0-9]*

.include "../../editors/emacs31/Makefile.common"

PKGREVISION=	2

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
