# $NetBSD: Makefile,v 1.89 2016/02/25 13:37:48 jperkin Exp $

DISTNAME=	xv-3.10a
PKGREVISION=	22
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://ftp.cis.upenn.edu/pub/xv/
DISTFILES=	${DEFAULT_DISTFILES} ${JUMBO_PATCHES}

PATCHFILES=	${JUMBO_PATCHES}
JUMBO_PATCHES=	xv-3.10a-jumbo-patches-20070520.tar.gz
PATCH_DIST_CAT.${JUMBO_PATCHES}=	${CAT} ${WRKDIR}/*-patch-*
PATCH_DIST_STRIP.${JUMBO_PATCHES}=	-p1
SITES.${JUMBO_PATCHES}=	${MASTER_SITE_SOURCEFORGE:=png-mng/}
PATCHFILES+=	xv-3.10a-enhancements.20070520-20081216.diff
PATCH_SITES=	http://www.gregroelofs.com/code/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.trilon.com/xv/
# and...	http://www.sonic.net/~roelofs/greg_xv.html
COMMENT=	X11 program that displays images of various formats
LICENSE=	xv-license

USE_IMAKE=	YES

# See the end of README in work/xv-3.10a for details.
RESTRICTED=	Distribution of modified copies and commercial distribution is not permitted.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

MAKEFLAGS+=	PREFIX=${PREFIX:Q}
MAKEFLAGS+=	PNGDIR=${BUILDLINK_PREFIX.png}
CPPFLAGS+=	-DDOCDIR=\""${PREFIX:Q}/share/doc/xv"\"

BUILD_TARGET=	depend all

SUBST_CLASSES+=		gspath
SUBST_FILES.gspath=	config.h
SUBST_SED.gspath=	-e 's|@PREFIX@|${PREFIX}|g'
SUBST_STAGE.gspath=	post-configure
SUBST_MESSAGE.gspath=	Fixing path to ghostscript interpreter.

INSTALLATION_DIRS+= share/doc/xv

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES.SunOS+=	ccflags
SUBST_FILES.ccflags=	Makefile
SUBST_SED.ccflags=	-e 's| CC = .*| CC = ${CC:Q}|'
SUBST_SED.ccflags+=	-e 's| CCOPTIONS = .*| CCOPTIONS = ${CFLAGS:Q}|'
SUBST_SED.ccflags+=	-e 's| CDEBUGFLAGS = .*| CDEBUGFLAGS =|'
SUBST_STAGE.ccflags=	post-configure
SUBST_MESSAGE.ccflags=	Fixing compiler flags for Solaris.

.if ${OPSYS} == "SunOS" || !empty(MACHINE_PLATFORM:MIRIX-5*)
CPPFLAGS+=	-DNEED_ALLOCA_H
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xv
	${INSTALL_DATA} ${WRKSRC}/docs/xvdocs.ps ${DESTDIR}${PREFIX}/share/doc/xv

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
