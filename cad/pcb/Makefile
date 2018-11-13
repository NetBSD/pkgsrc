# $NetBSD: Makefile,v 1.92 2018/11/13 04:09:24 dmcmahill Exp $
#

DISTNAME=	pcb-4.1.3
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcb/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://pcb.geda-project.org/
COMMENT=	Printed circuit board layout system
LICENSE=	gnu-gpl-v2

DEPENDS+=	gettext-tools>=0.14.6:../../devel/gettext-tools

CONFLICTS+=	pcb-current-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		WISH=${TOOLS_PATH.wish}
# work around a problem where the configure script uses
# AM_PROG_LEX and follows it with an AC_PATH_PROG to try
# and make sure that lex really does exist.  Unfortunately
# that test is thrown off by pkgsrc giving a full path for LEX.
# so, bypass the test and put our desired result directly into the
# configure cache.  Same for YACC.
CONFIGURE_ENV+=		ac_cv_path_LEX_PATH=${TOOLS_PATH.lex}
CONFIGURE_ENV+=		ac_cv_path_YACC_PATH=${TOOLS_PATH.bison}
CONFIGURE_ARGS+=	--disable-update-desktop-database
CONFIGURE_ARGS+=	--disable-update-mime-database
USE_TOOLS+=		bison gm4:run gmake intltool lex wish:run pkg-config
USE_PKGLOCALEDIR=	yes
INFO_FILES=		yes
LDFLAGS+=		-lstdc++  -lm # direct link as required by ld v2.22

USE_LANGUAGES=		c c++

PKG_OPTIONS_VAR=		PKG_OPTIONS.pcb
PKG_SUPPORTED_OPTIONS=		png gl
PKG_OPTIONS_REQUIRED_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		batch gtk motif
PKG_SUGGESTED_OPTIONS=		gtk png gl

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmotif)
.include "../../mk/motif.buildlink3.mk"
CONFIGURE_ARGS+=	--with-gui=lesstif
.elif !empty(PKG_OPTIONS:Mgtk)
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gui=gtk
# users who use the GTK gui on an X server which does
# not support GL (tightvnc for exmple) will need
# to disable GL
.  if empty(PKG_OPTIONS:Mgl)
CONFIGURE_ARGS+=	--disable-gl
.  endif
.elif !empty(PKG_OPTIONS:Mbatch)
CONFIGURE_ARGS+=	--with-gui=none
.else
PKG_FAIL_REASON+=	Invalid options
.endif

# dbus is only needed if we are building a gui (lesstif/gtk)
.if empty(PKG_OPTIONS:Mbatch)
.include "../../sysutils/dbus/buildlink3.mk"
.endif

EXPORTERS=	bom gcode gerber gsvit ipcd356 ps
.if !empty(PKG_OPTIONS:Mpng)
# these three need gd
EXPORTERS+=	gcode nelma png
.include "../../graphics/gd/buildlink3.mk"
.endif

CONFIGURE_ARGS+=	--with-exporters=${EXPORTERS:Q}

post-extract:
	${CHMOD} -R go-w ${WRKSRC}

# remove some stuff that is either broken or unmaintained
# and would require another runtime depends
post-install:
	${RM} ${DESTDIR}${PREFIX}/share/pcb/tools/PCB2HPGL
	${RM} ${DESTDIR}${PREFIX}/share/pcb/tools/tgo2pcb.tcl

.include "../../devel/gettext-lib/buildlink3.mk"
# NOTE:  glib is needed by the core of pcb and not just the GTK gui.
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
