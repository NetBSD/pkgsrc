# $NetBSD: Makefile,v 1.26 2005/05/22 20:07:54 jlam Exp $
#

DISTNAME=	pilrc-2.9p9
PKGNAME=	pilrc-2.9.10
PKGREVISION=	3
#WRKSRC=	${WRKDIR}/pilrc-2.9p9
EXTRACT_SUFX=	.tgz
CATEGORIES=	devel
MASTER_SITES=	http://www.ardiri.com/download/files/palm/		\
		http://www.ardiri.com/download/palm/pilrc/archive/

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		pilrc-2.9p10.diff
PATCH_DIST_STRIP+=	-p1
#
# The pilrc patches don't have Unix line endings, so strip off the extra
# \r character on each line.
#
PATCH_DIST_CAT=		${CAT} $$patchfile | ${TR} -d '\015'

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ardiri.com/index.cfm?redir=palm&cat=pilrc
COMMENT=	Generate resources for PalmOS applications from textual description

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

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
.else
CONFIGURE_ARGS+=--disable-pilrcui
PLIST_SUBST+=	PILRCUI="@comment "
.endif

#post-extract:
#	${CHMOD} +x ${WRKSRC}/configure
#	${CHMOD} +x ${WRKSRC}/missing

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/images
	cd ${WRKSRC}/doc &&						\
		${INSTALL_DATA} archive.html download.html index.html	\
		contrib.html history.html manual.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/images/download.gif ${DOCDIR}/images

.include "../../mk/bsd.pkg.mk"
