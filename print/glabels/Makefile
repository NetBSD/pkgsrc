# $NetBSD: Makefile,v 1.58 2012/09/15 10:06:10 obache Exp $
#

DISTNAME=		glabels-2.2.8
PKGREVISION=		19
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=glabels/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://glabels.sourceforge.net/
COMMENT=		Program for creating labels and business cards for GNOME

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

# This (a SUBST) is hefty enough to be in its own file.
.include "glib2-fixes.mk"

PKG_OPTIONS_VAR=        PKG_OPTIONS.glabels
PKG_SUPPORTED_OPTIONS=  evolution
PKG_SUGGESTED_OPTIONS=  evolution
.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mevolution)
.include "../../mail/evolution-data-server/buildlink3.mk"
.endif

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
