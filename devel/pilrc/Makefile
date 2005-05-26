# $NetBSD: Makefile,v 1.27 2005/05/26 10:22:47 dillo Exp $
#

DISTNAME=	pilrc-3.2
#WRKSRC=	${WRKDIR}/pilrc-2.9p9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pilrc/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://pilrc.sourceforge.net/
COMMENT=	Generate resources for PalmOS applications from textual description

GNU_CONFIGURE=	YES
CONFIGURE_SCRIPT=unix/configure

DOCDIR=		${PREFIX}/share/doc/html/pilrc

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=		PKG_OPTIONS.pilrc
PKG_SUPPORTED_OPTIONS=		gtk
PKG_SUGGESTED_OPTIONS=		gtk

# PILRC_USE_GTK should be removed after the pkgsrc-2005Q3 branch.
PKG_OPTIONS_LEGACY_VARS+=	PILRC_USE_GTK:gtk

.include "../../mk/bsd.options.mk"

###
### gtk -- Build the GTK+ UI
###
.if !empty(PKG_OPTIONS:Mgtk)
.  include "../../x11/gtk/buildlink3.mk"
PLIST_SUBST+=	PILRCUI=
CONFIGURE_ARGS+=--enable-pilrcui
.else
PLIST_SUBST+=	PILRCUI="@comment "
.endif

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/images
	cd ${WRKSRC}/doc &&						\
		${INSTALL_DATA} archive.html download.html index.html	\
		contrib.html history.html manual.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/images/download.gif ${DOCDIR}/images

.include "../../mk/bsd.pkg.mk"
