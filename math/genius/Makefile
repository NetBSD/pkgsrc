# $NetBSD: Makefile,v 1.2 2006/09/06 11:54:46 obache Exp $
#

DISTNAME=		genius-0.7.5
CATEGORIES=		math
MASTER_SITES=		http://ftp.5z.com/pub/genius/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ftp.5z.com/pub/genius/
COMMENT=		Calculator and math tool

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake intltool msgfmt
USE_DIRS+=		gnome2-1.5
USE_GNU_READLINE=	yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
