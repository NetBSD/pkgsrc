# $NetBSD: Makefile,v 1.4 2003/02/14 20:18:03 jmmv Exp $
#

DISTNAME=		libgnomedb-0.10.0
CATEGORIES=		databases gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgnomedb/0.10/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://www.gnome-db.org/
COMMENT=		GNOME2 database library

DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libgnomedb.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

EGDIR=		${PREFIX}/share/examples/libgnomedb
.if defined(PKG_SYSCONFDIR.gnome-vfs2)
CONF_FILES=	${EGDIR}/database-module.conf \
		${PKG_SYSCONFBASE.gnome-vfs2}/gnome-vfs-2.0/modules/database-module.conf
.else
CONF_FILES=	${EGDIR}/database-module.conf \
		${PKG_SYSCONFBASE}/gnome-vfs-2.0/modules/database-module.conf
.endif

GCONF2_SCHEMAS=		libgnomedb.schemas

.include "../../databases/libgda/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/bonobo-activation/buildlink2.mk"
.include "../../devel/libbonoboui/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
