# $NetBSD: Makefile,v 1.13 2008/01/18 05:08:31 tnn Exp $
#

DISTNAME=		genius-1.0.2
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		http://ftp.5z.com/pub/genius/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.jirka.org/genius.html
COMMENT=		Calculator and math tool

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake intltool msgfmt
USE_DIRS+=		gnome2-1.5
USE_GNU_READLINE=	yes

do-test:
	(cd ${WRKSRC}/src; perl geniustest.pl)

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
