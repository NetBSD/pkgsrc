# $NetBSD: options.mk,v 1.10 2011/11/11 03:12:10 jmmv Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.glib2
PKG_SUPPORTED_OPTIONS=	kqueue
PKG_SUGGESTED_OPTIONS=	# empty

# We really should be doing this by default.  However, the kqueue patch is not
# official, needs some more testing and, due to the way it is written, forces
# us to run autoconf.  If the code gets integrated upstream, there is no reason
# for us to provide a 'kqueue' option here and it should just go away.
#
#.if exists(/usr/include/sys/event.h)
#PKG_SUGGESTED_OPTIONS+=	kqueue
#.endif

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if $(PKG_OPTIONS:Mkqueue)
PATCH_SITES=		http://dmitrymatveev.co.uk/files/
PATCHFILES=		glib-gio-kqueue-2.28.8-v1.patch
PATCH_DIST_STRIP=	-p0

USE_TOOLS+=	autoconf autoheader automake
pre-configure: regen-autotools
regen-autotools:
	cd ${WRKSRC} && automake
	cd ${WRKSRC} && autoheader
	cd ${WRKSRC} && autoconf
.endif
