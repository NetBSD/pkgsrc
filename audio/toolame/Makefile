# $NetBSD: Makefile,v 1.17 2007/07/14 19:12:22 heinz Exp $
#

DISTNAME=	toolame-02l
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=toolame/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/toolame/
COMMENT=	Optimized MPEG 1/2 layer 2 audio encoder

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake

TOOLAME_ARCH?=

MAKE_ENV+=	CC=${CC:Q} CFLAGS=${CFLAGS:M*:Q} ARCH=${TOOLAME_ARCH:Q}
BUILD_TARGET=	toolame

INSTALLATION_DIRS=	bin

TOOLAME_HTMLFILES= changes.html default.html psycho.html readme.html vbr.html
do-install:
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${PREFIX:Q}/share/doc/html/toolame
	cd ${WRKSRC:Q}/html; ${INSTALL_DATA} ${TOOLAME_HTMLFILES} \
		${DESTDIR:Q}${PREFIX:Q}/share/doc/html/toolame
	${INSTALL_PROGRAM} ${WRKSRC:Q}/toolame ${DESTDIR:Q}${PREFIX:Q}/bin

.include "../../mk/bsd.pkg.mk"
