# $NetBSD: Makefile,v 1.14 2005/03/26 16:20:27 jmmv Exp $
#

DISTNAME=	evolution-data-server-1.2.1
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/evolution-data-server/1.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://ximian.com/products/evolution/
COMMENT=	Evolution data server

BUILD_USES_MSGFMT=	yes
BUILD_DEPENDS+=		bison>=1.875:../../devel/bison

BUILDLINK_DEPENDS.libsoup-devel+=	libsoup-devel>=2.2.2

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make yacc
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
YACC=			${LOCALBASE}/bin/bison # XXX

PKG_OPTIONS_VAR=	PKG_OPTIONS.evolution-data-server
PKG_SUPPORTED_OPTIONS=	inet6
.include "../../mk/bsd.options.mk"

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--with-nspr-includes=${BUILDLINK_PREFIX.nspr}/include/nspr
CONFIGURE_ARGS+=	--with-nspr-libs=${BUILDLINK_PREFIX.nspr}/lib
CONFIGURE_ARGS+=	--with-nss-includes=${BUILDLINK_PREFIX.nss}/include/nss/nss
CONFIGURE_ARGS+=	--with-nss-libs=${BUILDLINK_PREFIX.nss}/lib
CONFIGURE_ARGS+=	--with-openldap

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

PKGCONFIG_OVERRIDE+=	addressbook/libebook/libebook.pc.in
PKGCONFIG_OVERRIDE+=	addressbook/libedata-book/libedata-book.pc.in
PKGCONFIG_OVERRIDE+=	calendar/libecal/libecal.pc.in
PKGCONFIG_OVERRIDE+=	calendar/libedata-cal/libedata-cal.pc.in
PKGCONFIG_OVERRIDE+=	camel/camel.pc.in
PKGCONFIG_OVERRIDE+=	camel/camel-provider.pc.in
PKGCONFIG_OVERRIDE+=	libedataserver/libedataserver.pc.in
PKGCONFIG_OVERRIDE+=	libedataserverui/libedataserverui.pc.in
PKGCONFIG_OVERRIDE+=	servers/groupwise/libegroupwise.pc.in
PKGCONFIG_OVERRIDE+=	evolution-data-server.pc.in

BUILDLINK_TRANSFORM+=	rm:-ldl

.include "../../databases/openldap/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../net/libsoup-devel/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
