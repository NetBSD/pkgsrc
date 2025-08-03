# $NetBSD: options.mk,v 1.3 2025/08/03 07:23:07 vins Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.xfile

PKG_SUPPORTED_OPTIONS=	dbus
#PKG_SUGGESTED_OPTIONS=	dbus

PLIST_VARS+=		dbus

.include "../../mk/bsd.options.mk"

##
## D-Bus
## Allows xfile to act as xdg/freedesktop default file manager and to be launched over dbus.
## Such interface is used by some GTK programs, notably firefox and gimp.
##
.if !empty(PKG_OPTIONS:Mdbus)
.  include "../../sysutils/dbus/buildlink3.mk"

DISTFILES+=	xfile-xdgsvc-src.tar.xz

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Setting XDG service prefix.
SUBST_FILES.prefix=	src/xfile.service
SUBST_SED.prefix+=	-e "s:/usr/bin:${PREFIX}/bin:g"

MAKE_ENV+=	DBUS=1
PLIST.dbus=	yes

.PHONY: xdgsvc-src

xdgsvc-src:
.  for f in xfile-xdg.c xfile.service
	${RUN}${MV} ${WRKDIR}/xfile-xdgsvc/${f} ${WRKSRC}/src
.  endfor

post-extract: xdgsvc-src

.endif
