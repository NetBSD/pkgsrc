# $NetBSD: Makefile,v 1.13 2003/09/19 22:19:50 jmmv Exp $
#

DISTNAME=		libgnomedb-1.0.0
CATEGORIES=		databases gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgnomedb/1.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://www.gnome-db.org/
COMMENT=		GNOME2 database library

BUILD_USES_MSGFMT=	yes
DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libgnomedb.pc.in

CONFIGURE_ARGS=		--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

GCONF2_SCHEMAS=		libgnomedb.schemas

.include "../../databases/libgda/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/bonobo-activation/buildlink2.mk"
.include "../../devel/libbonoboui/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
