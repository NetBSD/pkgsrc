# $NetBSD: Makefile,v 1.7 2004/10/04 09:46:50 jmmv Exp $
#

DISTNAME=	evolution-data-server-1.0.1
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/evolution-data-server/1.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://ximian.com/products/evolution/
COMMENT=	Evolution data server

BUILD_USES_MSGFMT=	yes
BUILD_DEPENDS+=		bison>=1.875:../../devel/bison

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make yacc
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
YACC=			${LOCALBASE}/bin/bison # XXX

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--with-openldap

PKGCONFIG_OVERRIDE+=	addressbook/libebook/libebook-1.0.pc.in
PKGCONFIG_OVERRIDE+=	addressbook/libedata-book/libedata-book-1.0.pc.in
PKGCONFIG_OVERRIDE+=	calendar/libecal/libecal-1.0.pc.in
PKGCONFIG_OVERRIDE+=	calendar/libedata-cal/libedata-cal-1.0.pc.in
PKGCONFIG_OVERRIDE+=	libedataserver/libedataserver-1.0.pc.in
PKGCONFIG_OVERRIDE+=	servers/groupwise/libegroupwise-1.0.pc.in
PKGCONFIG_OVERRIDE+=	evolution-data-server-1.0.pc.in

.include "../../databases/openldap/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../net/libsoup-devel/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
