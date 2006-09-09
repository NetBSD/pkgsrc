# $NetBSD: Makefile,v 1.66 2006/09/09 02:42:02 obache Exp $

DISTNAME=	xv-3.10a
PKGREVISION=	12
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://ftp.cis.upenn.edu/pub/xv/
#DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

PATCHFILES=	xv-3.10a-jumbo-patches-20050501.tar.bz2
PATCH_SITES=	${MASTER_SITE_SOURCEFORGE:=png-mng/}
PATCH_DIST_CAT=		${BZCAT} $$patchfile | ${TAR} -Oxf - "*-patch-*"
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.trilon.com/xv/
# and...	http://www.sonic.net/~roelofs/greg_xv.html
COMMENT=	X11 program that displays images of various formats

USE_IMAKE=	YES

# See the end of README in work/xv-3.10a for details.
RESTRICTED=	Distribution of modified copies and commercial distribution is not permitted.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

LICENSE=	xv-license

.include "../../mk/bsd.prefs.mk"

.if !empty(LOWER_OPSYS:Mirix5*)
CPPFLAGS+=	-DNEED_ALLOCA_H
.endif

pre-configure:
	${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.orig &&		\
		${SED} -e 's|@LOCALBASE@|${LOCALBASE}|g'		\
		${WRKSRC}/config.h.orig > ${WRKSRC}/config.h

.if ${OPSYS} == "SunOS"
post-configure:
	${MV} ${WRKSRC}/${MAKE_FILE} ${WRKSRC}/${MAKE_FILE}.orig &&	\
		${SED} -e 's| CC = .*| CC = ${CC}|'			\
		-e 's| CCOPTIONS = .*| CCOPTIONS = ${CFLAGS}|'		\
		-e 's| CDEBUGFLAGS = .*| CDEBUGFLAGS =|'		\
		${WRKSRC}/${MAKE_FILE}.orig > ${WRKSRC}/${MAKE_FILE}
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xv
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xv
	${INSTALL_DATA} ${WRKSRC}/docs/xvdocs.ps ${PREFIX}/share/doc/xv

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
