# $NetBSD: Makefile,v 1.21 2012/10/02 23:48:11 asau Exp $

DISTNAME=	toolame-02l
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=toolame/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/toolame/
COMMENT=	Optimized MPEG 1/2 layer 2 audio encoder
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		gmake

TOOLAME_ARCH?=

MAKE_ENV+=	CC=${CC:Q} CFLAGS=${CFLAGS:Q} LDFLAGS=${LDFLAGS:Q} ARCH=${TOOLAME_ARCH:Q}
BUILD_TARGET=	toolame

INSTALLATION_DIRS=	bin share/doc/toolame

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
SUBST_CLASSES+=		inline
SUBST_MESSAGE.inline=	Disable inline on Sun Studio
SUBST_STAGE.inline=	post-patch
SUBST_FILES.inline=	Makefile
SUBST_SED.inline=	-e 's,INLINE=inline,INLINE=,'
.endif

TOOLAME_HTMLFILES= changes.html default.html psycho.html readme.html vbr.html
do-install:
	cd ${WRKSRC}/html; ${INSTALL_DATA} ${TOOLAME_HTMLFILES} \
		${DESTDIR}${PREFIX}/share/doc/toolame
	${INSTALL_PROGRAM} ${WRKSRC}/toolame ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
