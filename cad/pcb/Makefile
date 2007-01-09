# $NetBSD: Makefile,v 1.38 2007/01/09 11:55:52 dmcmahill Exp $
#

DISTNAME=	pcb-${SNAPDATE}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcb/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://pcb.sourceforge.net/
COMMENT=	Printed circuit board layout system

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	pcb-current-[0-9]*

SNAPDATE=		20060822
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		WISH=${TOOLS_PATH.wish}
USE_TOOLS+=		bison gm4:run gmake lex wish:run pkg-config
INFO_FILES=		yes

PKG_OPTIONS_VAR=		PKG_OPTIONS.pcb
PKG_SUPPORTED_OPTIONS=		png
PKG_OPTIONS_REQUIRED_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		batch gtk motif
PKG_SUGGESTED_OPTIONS=		gtk png

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmotif)
.include "../../mk/motif.buildlink3.mk"
CONFIGURE_ARGS+=	--with-gui=lesstif
.elif !empty(PKG_OPTIONS:Mgtk)
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gui=gtk
.elif !empty(PKG_OPTIONS:Mbatch)
CONFIGURE_ARGS+=	--with-gui=none
.else
PKG_FAIL_REASON=	Invalid options
.endif

EXPORTERS=	bom gerber ps
.if !empty(PKG_OPTIONS:Mpng)
EXPORTERS+=	png
.include "../../graphics/gd/buildlink3.mk"
.endif

CONFIGURE_ARGS+=	--with-exporters=${EXPORTERS:Q}

.include "../../mk/bsd.pkg.mk"
