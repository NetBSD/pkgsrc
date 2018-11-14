# $NetBSD: Makefile,v 1.38 2018/11/14 22:21:51 kleink Exp $
#

.include "Makefile.common"

PKGREVISION=	11
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	On-screen Input Pad to Send Characters with Mouse

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config intltool msgfmt xgettext msgmerge

PKGCONFIG_OVERRIDE+=	input-pad.pc.in

CONFIGURE_ARGS+=	--enable-pygobject2=no
CONFIGURE_ARGS+=	--disable-maintainer-mode

MANCOMPRESSED=		yes

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxklavier+=	libxklavier>=4.0
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
