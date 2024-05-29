# $NetBSD: Makefile,v 1.100 2024/05/29 16:33:27 adam Exp $

DISTNAME=		genius-1.0.27
PKGREVISION=		6
CATEGORIES=		math
MASTER_SITES=		http://ftp.5z.com/pub/genius/
MASTER_SITES+=		${MASTER_SITE_GNOME:=sources/genius/1.0/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.jirka.org/genius.html
COMMENT=		Calculator and math tool
LICENSE=		gnu-gpl-v3

USE_LANGUAGES=		c99

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake intltool msgfmt perl:test

do-test:
	cd ${WRKSRC}/src; perl geniustest.pl

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtksourceview4/buildlink3.mk"
.include "../../x11/vte3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
