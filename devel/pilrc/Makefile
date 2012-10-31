# $NetBSD: Makefile,v 1.34 2012/10/31 11:19:25 asau Exp $
#

DISTNAME=	pilrc-3.2
#WRKSRC=	${WRKDIR}/pilrc-2.9p9
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pilrc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pilrc.sourceforge.net/
COMMENT=	Generate resources for PalmOS applications from textual description

GNU_CONFIGURE=	YES
CONFIGURE_SCRIPT=unix/configure

DOCDIR=		${PREFIX}/share/doc/html/pilrc

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

INSTALLATION_DIRS=	${DOCDIR}/images

post-install:
	cd ${WRKSRC}/doc &&						\
		${INSTALL_DATA} archive.html download.html index.html	\
		contrib.html history.html manual.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/images/download.gif ${DESTDIR}${DOCDIR}/images

.include "../../mk/bsd.pkg.mk"
