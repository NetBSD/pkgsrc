# $NetBSD: Makefile,v 1.4 2001/05/02 09:25:56 zuntum Exp $
#

DISTNAME=	pilrc-2_7b
PKGNAME=	pilrc-2.7b
CATEGORIES=	devel
MASTER_SITES=	http://www.ardiri.com/download/palm/pilrc/archive/
#PATCH_SITES=	http://www.ardiri.com/download/palm/pilrc/patch/
EXTRACT_SUFX=	.zip

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.ardiri.com/index.cfm?redir=palm&cat=pilrc
COMMENT=	generate resources for PalmOS applications from textual description

# LP64 problems - pilrc.c has: Assert(sizeof(char *) == sizeof(int));
NOT_FOR_PLATFORM= *-*-alpha *-*-sparc64

.include "../../mk/bsd.prefs.mk"

PILRC_USE_GTK?=	YES
.if ${PILRC_USE_GTK} == YES
DEPENDS+=	gtk+>=1.2.0:../../x11/gtk
PLIST_SUBST+=	PILRCUI=''
.else
CONFIGURE_ARGS+=--disable-pilrcui
PLIST_SUBST+=	PILRCUI='@comment '
.endif

EXTRACT_CMD=	unzip -aq ${DOWNLOADED_DISTFILE}

WRKSRC=		${WRKDIR}/${PKGNAME}
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
