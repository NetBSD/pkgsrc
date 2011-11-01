# $NetBSD: Makefile,v 1.99 2011/11/01 06:02:01 sbd Exp $
#

DISTNAME=		gcalctool-5.32.2
PKGREVISION=		4
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gcalctool/5.32/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://live.gnome.org/Gcalctool
COMMENT=		Desktop calculator for GNOME

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		HAVE_YACC=yes

USE_LIBTOOL=		yes
USE_TOOLS+=		bison gmake intltool flex msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

BUILD_DEPENDS+=	gsed-[0-9]*:../../textproc/gsed

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.18.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
