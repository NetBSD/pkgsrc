# $NetBSD: Makefile,v 1.1.1.1 2002/10/30 05:09:08 rh Exp $
#

DISTNAME=		libgnomedb-0.8.199
CATEGORIES=		databases gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgnomedb/0.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://www.gnome-db.org/
COMMENT=		GNOME2 database library

USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libgnomedb.pc.in

.include "../../databases/libgda/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../devel/bonobo-activation/buildlink2.mk"
.include "../../devel/libbonoboui/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
