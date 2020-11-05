# $NetBSD: Makefile,v 1.22 2020/11/05 09:07:39 ryoon Exp $
#

DISTNAME=	tilp2-1.16
PKGREVISION=	20
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tilp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lpg.ticalc.org/prj_tilp/
COMMENT=	Multi-platform linking program for TI graphing calculators
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake intltool msgfmt msgmerge pkg-config xgettext

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../comms/libtifiles2/buildlink3.mk"
.include "../../comms/libticonv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../comms/libticalcs2/buildlink3.mk"
.include "../../comms/libticables2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
