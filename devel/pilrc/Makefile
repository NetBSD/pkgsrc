# $NetBSD: Makefile,v 1.38 2020/03/20 11:57:30 nia Exp $
#

DISTNAME=	pilrc-3.2
#WRKSRC=	${WRKDIR}/pilrc-2.9p9
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pilrc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pilrc.sourceforge.net/
COMMENT=	Generate resources for PalmOS applications from textual description

GNU_CONFIGURE=		YES
CONFIGURE_SCRIPT=	unix/configure

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=		PKG_OPTIONS.pilrc
PKG_SUPPORTED_OPTIONS=		gtk
PKG_SUGGESTED_OPTIONS=		gtk

.include "../../mk/bsd.options.mk"

###
### gtk -- Build the GTK+ UI
###
PLIST_VARS+=	pilrcui
.if !empty(PKG_OPTIONS:Mgtk)
.  include "../../x11/gtk/buildlink3.mk"
PLIST.pilrcui=		yes
CONFIGURE_ARGS+=	--enable-pilrcui
.endif

AUTO_MKDIRS=		yes

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html \
		${DESTDIR}${PREFIX}/share/doc/pilrc
	cd ${WRKSRC}/doc/images && ${INSTALL_DATA} download.gif \
		${DESTDIR}${PREFIX}/share/doc/pilrc/images

.include "../../mk/bsd.pkg.mk"
