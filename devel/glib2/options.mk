# $NetBSD: options.mk,v 1.18 2012/10/06 20:44:04 prlw1 Exp $

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
PATCH_SITES=		http://distfiles.bsdfrog.org/
PATCHFILES=		glib-gio-kqueue-2.32.4-v3.patch
PATCH_DIST_STRIP=	-p1

BUILD_DEPENDS+=	gtk-doc>=1.17nb1:../../textproc/gtk-doc
USE_TOOLS+=	aclocal autoconf autoheader automake
pre-configure: regen-autotools
regen-autotools:
	cd ${WRKSRC} && aclocal
	cd ${WRKSRC} && automake
	cd ${WRKSRC} && autoheader
	cd ${WRKSRC} && autoconf
.endif
