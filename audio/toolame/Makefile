# $NetBSD: Makefile,v 1.8 2004/12/03 15:14:51 wiz Exp $
#

DISTNAME=	toolame-02l
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=toolame/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/toolame/
COMMENT=	Optimized MPEG 1/2 layer 2 audio encoder

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

TOOLAME_ARCH?=

MAKE_ENV+=	CC="${CC}" CFLAGS="${CFLAGS}" ARCH="${TOOLAME_ARCH}"
BUILD_TARGET=	toolame

TOOLAME_HTMLFILES= changes.html default.html psycho.html readme.html vbr.html
do-install:
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/doc/html/toolame
	cd ${WRKSRC}/html; ${INSTALL_DATA} ${TOOLAME_HTMLFILES} \
		${LOCALBASE}/share/doc/html/toolame
	${INSTALL_PROGRAM} ${WRKSRC}/toolame ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
