# $NetBSD: Makefile,v 1.7 2002/07/11 14:24:01 abs Exp $
#

PKGNAME=	${DISTNAME:C/-/player-/}
PKGREVISION=	1

DEPENDS+=	libflash-[0-9]*:../libflash

COMMENT=	standalone open source flash(tm) player

DISTINFO_FILE=	${.CURDIR}/../libflash/distinfo
FILESDIR=	${.CURDIR}/../libflash/files
PATCHDIR=	${.CURDIR}/../libflash/patches

do-build:
		cd ${WRKSRC}/Player && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
		cd ${WRKSRC}/Player && ${INSTALL_PROGRAM} swfplayer ${PREFIX}/bin

.include "../libflash/Makefile.common"
