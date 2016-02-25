# $NetBSD: Makefile,v 1.53 2016/02/25 13:19:47 jperkin Exp $

DISTNAME=	linuxdoom-1.10
PKGNAME=	xdoom-1.10
PKGREVISION=	4
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/source/
MASTER_SITES+=	ftp://ftp.idsoftware.com/idstuff/doom/
DISTFILES=	doomsrc.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=	http://www.idsoftware.com/archives/doomarc.html
# AWOL
COMMENT=	3D shoot-em-up for 8-bit X11 displays
LICENSE=	xdoom-license

DEPENDS+=	doom1-[0-9]*:../../games/doom1

WRKSRC=		${WRKDIR}
USE_TOOLS+=	gmake gunzip tar unzip
MAKE_ENV+=	X11BASE=${X11BASE:Q} INSTALL_PREFIX=${PREFIX:Q}

BROKEN_ON_PLATFORM=	${LP64PLATFORMS}

.include "../../mk/bsd.prefs.mk"

CFLAGS.Linux+=	-DLINUX

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-D__BIG_ENDIAN__=1
.endif

INSTALLATION_DIRS=	bin

post-extract:
	(cd ${WRKDIR}; ${TAR} xzf linuxdoom-1.10.src.tgz)
	(cd ${WRKDIR}; ${TAR} xzf sndserv.tgz)

do-build:
	cd ${WRKSRC}/${DISTNAME} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}
	cd ${WRKSRC}/sndserv && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME}/linux/linuxxdoom \
		${DESTDIR}${PREFIX}/bin/xdoom
	${INSTALL_PROGRAM} ${WRKSRC}/sndserv/linux/sndserver \
		${DESTDIR}${PREFIX}/bin/sndserver

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
