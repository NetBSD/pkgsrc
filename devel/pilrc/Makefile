# $NetBSD: Makefile,v 1.21 2004/04/25 02:53:46 snj Exp $
#

DISTNAME=	pilrc-2.9p9
PKGNAME=	pilrc-2.9.10
PKGREVISION=	2
#WRKSRC=	${WRKDIR}/pilrc-2.9p9
DIFFS=		pilrc-2.9p10.diff
EXTRACT_SUFFIX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFFIX} ${DIFFS}
CATEGORIES=	devel
MASTER_SITES=	http://www.ardiri.com/download/files/palm/
#MASTER_SITES=	http://www.ardiri.com/download/palm/pilrc/archive/
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFFIX}

# we can't use this, since pilrc's maintainer won't create patches with
# unix line endings
#PATCH_SITES=	${MASTER_SITES}
#PATCHFILES=	pilrc-2.9p10.diff
#PATCH_DIST_STRIP+=-p1

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ardiri.com/index.cfm?redir=palm&cat=pilrc
COMMENT=	Generate resources for PalmOS applications from textual description

#EXTRACT_CMD=	unzip -aq ${DOWNLOADED_DISTFILE}

USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

DOCDIR=		${PREFIX}/share/doc/html/pilrc

.include "../../mk/bsd.prefs.mk"

PILRC_USE_GTK?=	YES

.if ${PILRC_USE_GTK} == YES
.include "../../x11/gtk/buildlink3.mk"
PLIST_SUBST+=	PILRCUI=''
.else
CONFIGURE_ARGS+=--disable-pilrcui
PLIST_SUBST+=	PILRCUI='@comment '
.endif

#post-extract:
#	${CHMOD} +x ${WRKSRC}/configure
#	${CHMOD} +x ${WRKSRC}/missing

pre-patch:
	cd ${WRKSRC} && ${TR} -d '\015' < ${DISTDIR}/${DIFFS} \
		| ${PATCH} --quiet -p1
post-install:
	${INSTALL_DATA_DIR} ${DOCDIR} ${DOCDIR}/images
	cd ${WRKSRC}/doc &&						\
		${INSTALL_DATA} archive.html download.html index.html	\
		contrib.html history.html manual.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/images/download.gif ${DOCDIR}/images

.include "../../mk/bsd.pkg.mk"
