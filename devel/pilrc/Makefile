# $NetBSD: Makefile,v 1.5 2001/05/11 08:14:33 dillo Exp $
#

DISTNAME=	pilrc-2.8p4
PKGNAME=	pilrc-2.8.4
CATEGORIES=	devel
MASTER_SITES=	http://www.ardiri.com/download/palm/pilrc/patch/
#MASTER_SITES=	http://www.ardiri.com/download/palm/pilrc/archive/
#EXTRACT_SUFX=	.zip

#PATCH_SITES=	http://www.ardiri.com/download/palm/pilrc/patch/
#PATCHFILES=	pilrc-2.8p0.diff pilrc-2.8p1.diff pilrc-2.8p2.diff
#PATCHFILES+=	pilrc-2.8p3.diff
#PATCH_DIST_STRIP+=-p1
#
MAINTAINER=	dillo@netbsd.org
HOMEPAGE=	http://www.ardiri.com/index.cfm?redir=palm&cat=pilrc
COMMENT=	generate resources for PalmOS applications from textual description

.include "../../mk/bsd.prefs.mk"

# pilrcui is broken in 2.8
#PILRC_USE_GTK?=	YES
PILRC_USE_GTK=	NO

.if ${PILRC_USE_GTK} == YES
DEPENDS+=	gtk+>=1.2.0:../../x11/gtk
PLIST_SUBST+=	PILRCUI=''
.else
CONFIGURE_ARGS+=--disable-pilrcui
PLIST_SUBST+=	PILRCUI='@comment '
.endif

#EXTRACT_CMD=	unzip -aq ${DOWNLOADED_DISTFILE}

WRKSRC=		${WRKDIR}/pilrc-2.8p4
GNU_CONFIGURE=	YES

DOCDIR=		${PREFIX}/share/doc/html/pilrc

post-extract:
	${CHMOD} +x ${WRKSRC}/configure
	${CHMOD} +x ${WRKSRC}/missing

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR} ${DOCDIR}/images
	cd ${WRKSRC}/doc &&						\
		${INSTALL_DATA} archive.html download.html index.html	\
		contrib.html history.html manual.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/images/download.gif ${DOCDIR}/images

.include "../../mk/bsd.pkg.mk"
