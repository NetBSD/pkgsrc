# $NetBSD: Makefile,v 1.4 2001/11/23 15:48:21 agc Exp $
#

PKGNAME=	${DISTNAME:C/-/player-/}
COMMONDIR=	../libflash

DEPENDS+=	libflash-[0-9]*:${COMMONDIR}

COMMENT=	standalone open source flash(tm) player

PATCHDIR=	${.CURDIR}/${COMMONDIR}/patches
FILESDIR=	${.CURDIR}/${COMMONDIR}/files

do-build:
		cd ${WRKSRC}/Player && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
		cd ${WRKSRC}/Player && ${INSTALL_PROGRAM} swfplayer ${PREFIX}/bin

.include "${COMMONDIR}/Makefile.common"
