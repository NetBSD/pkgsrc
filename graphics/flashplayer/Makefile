# $NetBSD: Makefile,v 1.6 2002/07/02 12:45:04 wiz Exp $
#

PKGNAME=	${DISTNAME:C/-/player-/}

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
