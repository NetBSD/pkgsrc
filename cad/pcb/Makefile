# $NetBSD: Makefile,v 1.37 2006/08/23 11:26:44 dmcmahill Exp $
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
PKG_OPTIONS_GROUP.gui=		gtk motif
PKG_SUGGESTED_OPTIONS=		png gtk

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmotif)
.include "../../mk/motif.buildlink3.mk"
CONFIGURE_ARGS+=	--with-gui=lesstif
.else
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gui=gtk
.endif

EXPORTERS=	bom gerber ps
.if !empty(PKG_OPTIONS:Mpng)
EXPORTERS+=	png
.include "../../graphics/gd/buildlink3.mk"
.endif

CONFIGURE_ARGS+=	--with-exporters=${EXPORTERS:Q}

.include "../../mk/bsd.pkg.mk"
