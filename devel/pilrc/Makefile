# $NetBSD: Makefile,v 1.9 2001/11/29 01:12:30 hubertf Exp $
#

DISTNAME=	pilrc-2.8p4
PKGNAME=	pilrc-2.8.4
PKGREVISION=	1
WRKSRC=		${WRKDIR}/pilrc-2.8p4
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

#EXTRACT_CMD=	unzip -aq ${DOWNLOADED_DISTFILE}

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

DOCDIR=		${PREFIX}/share/doc/html/pilrc

.include "../../mk/bsd.prefs.mk"

PILRC_USE_GTK?=	YES

.if ${PILRC_USE_GTK} == YES
.include "../../x11/gtk/buildlink.mk"
PLIST_SUBST+=	PILRCUI=''
.else
CONFIGURE_ARGS+=--disable-pilrcui
PLIST_SUBST+=	PILRCUI='@comment '
.endif

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
