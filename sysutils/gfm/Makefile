# $NetBSD: Makefile,v 1.20 2020/06/02 08:24:45 adam Exp $
#

DISTNAME=	gfm-1.06
PKGREVISION=	18
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tilp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lpg.ticalc.org/prj_tilp/
COMMENT=	Group File Manager for TI hand-helds
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake intltool msgfmt msgmerge pkg-config xgettext

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../comms/libticalcs2/buildlink3.mk"
.include "../../comms/libtifiles2/buildlink3.mk"
.include "../../comms/libticonv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
