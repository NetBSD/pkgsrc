# $NetBSD: Makefile,v 1.19 2024/07/11 19:53:34 wiz Exp $

CONFLICTS+=	emacs29-nox11-[0-9]*

#PKGREVISION=	0
PKGREVISION= 1
.include "../../editors/emacs29/Makefile.common"

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
