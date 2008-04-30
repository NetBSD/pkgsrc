# $NetBSD: Makefile,v 1.65 2008/04/30 13:38:15 jmmv Exp $
#

DISTNAME=	evolution-data-server-2.22.1
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/evolution-data-server/2.22/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/evolution/
COMMENT=	Evolution data server

BUILDLINK_API_DEPENDS.libsoup-devel+=	libsoup-devel>=2.2.3

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		bison gmake intltool msgfmt pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

PYTHON_FOR_BUILD_ONLY=	YES
PYTHON_PATCH_SCRIPTS=	addressbook/libebook/gen-western-table.py

PKG_OPTIONS_VAR=	PKG_OPTIONS.evolution-data-server
PKG_SUPPORTED_OPTIONS=	inet6
.include "../../mk/bsd.options.mk"

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ENV+=		PTHREAD_LIB="${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}"

.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M1.6.2)
.include "../../devel/pthread-sem/buildlink3.mk"
LIBS+=		-lsemaphore
.endif

.if ${OPSYS} == "Darwin"
CPPFLAGS+=	-DBIND_8_COMPAT
.endif

CONFIGURE_ARGS+=	--with-nspr-includes=${BUILDLINK_PREFIX.nspr}/include/nspr
CONFIGURE_ARGS+=	--with-nspr-libs=${BUILDLINK_PREFIX.nspr}/lib
CONFIGURE_ARGS+=	--with-nss-includes=${BUILDLINK_PREFIX.nss}/include/nss/nss
CONFIGURE_ARGS+=	--with-nss-libs=${BUILDLINK_PREFIX.nss}/lib
CONFIGURE_ARGS+=	--with-openldap
CONFIGURE_ARGS+=	--with-libdb=${LOCALBASE}
BUILDLINK_TRANSFORM+=	l:db:db4

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

.if ${OPSYS} == "NetBSD"
# zone.tab file in /usr/share/zoneinfo
DEPENDS+= zonetab-[0-9]*:../../time/zonetab
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
