# $NetBSD: Makefile,v 1.1.1.1 2001/04/25 17:39:16 wiz Exp $
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

WRKSRC=		${WRKDIR}/pilrc-2.7b
GNU_CONFIGURE=	YES

DOCDIR=		${PREFIX}/share/doc/html/pilrc

post-extract:
	${CHMOD} +x ${WRKSRC}/configure

post-install:
	${MKDIR} ${DOCDIR}
	${MKDIR} ${DOCDIR}/images
	for f in archive.html download.html index.html contrib.html \
		history.html manual.html ; \
	do \
		${INSTALL_DATA} ${WRKSRC}/doc/$$f ${DOCDIR} ; \
	done
	${INSTALL_DATA}  ${WRKSRC}/doc/images/download.gif ${DOCDIR}/images

.include "../../mk/bsd.pkg.mk"
