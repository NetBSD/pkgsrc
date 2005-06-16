# $NetBSD: Makefile,v 1.11 2005/06/16 06:57:39 jlam Exp $
#

DISTNAME=	toolame-02l
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=toolame/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/toolame/
COMMENT=	Optimized MPEG 1/2 layer 2 audio encoder

USE_TOOLS+=		gmake

TOOLAME_ARCH?=

MAKE_ENV+=	CC="${CC}" CFLAGS="${CFLAGS}" ARCH="${TOOLAME_ARCH}"
BUILD_TARGET=	toolame

INSTALLATION_DIRS=	bin

TOOLAME_HTMLFILES= changes.html default.html psycho.html readme.html vbr.html
do-install:
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/doc/html/toolame
	cd ${WRKSRC}/html; ${INSTALL_DATA} ${TOOLAME_HTMLFILES} \
		${LOCALBASE}/share/doc/html/toolame
	${INSTALL_PROGRAM} ${WRKSRC}/toolame ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
