# $NetBSD: Makefile,v 1.2 2001/02/16 15:22:17 wiz Exp $
#

PKGNAME=	${DISTNAME:C/-/player-/}
COMMONDIR=	../libflash

DEPENDS+=	libflash-*:${COMMONDIR}

COMMENT=	standalone open source flash(tm) player

PATCHDIR=	${.CURDIR}/${COMMONDIR}/patches
FILESDIR=	${.CURDIR}/${COMMONDIR}/files

do-build:
		cd ${WRKSRC}/Player && make

do-install:
		cd ${WRKSRC}/Player && ${INSTALL_PROGRAM} swfplayer ${PREFIX}/bin

.include "${COMMONDIR}/Makefile.common"
