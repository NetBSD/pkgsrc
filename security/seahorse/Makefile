# $NetBSD: Makefile,v 1.57 2006/09/16 12:20:32 jmmv Exp $

DISTNAME=	seahorse-0.8.1
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/seahorse/0.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seahorse.sourceforge.net/
COMMENT=	GnuPG front end and bonobo component for GNOME

DEPENDS+=		gnupg>=1.2.1:../../security/gnupg

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--disable-gedit
CONFIGURE_ARGS+=	--disable-nautilus

GCONF2_SCHEMAS= 	seahorse.schemas

BUILDLINK_API_DEPENDS.gpgme+=	gpgme>=1.0.1nb2

.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../net/libsoup-devel/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
