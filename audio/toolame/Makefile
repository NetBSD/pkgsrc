# $NetBSD: Makefile,v 1.1.1.1 2003/06/23 07:07:26 mrg Exp $
#

DISTNAME=	toolame-02l
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=toolame/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/toolame/
COMMENT=	toolame is an optimized mpeg 1/2 layer 2 audio encoder

LICENSE=	fee-based-commercial-use

USE_BUILDLINK2=		yes
USE_GMAKE=		yes

TOOLAME_ARCH?=

MAKE_ENV+=	CC="${CC}" CFLAGS="${CFLAGS}" ARCH="${TOOLAME_ARCH}"
ALL_TARGET=	toolame

TOOLAME_HTMLFILES= changes.html default.html psycho.html readme.html vbr.html
do-install:
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/doc/html/toolame
	cd ${WRKSRC}/html; ${INSTALL_DATA} ${TOOLAME_HTMLFILES} \
		${LOCALBASE}/share/doc/html/toolame
	${INSTALL_PROGRAM} ${WRKSRC}/toolame ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
