# $NetBSD: Makefile,v 1.1.1.1 2000/08/28 17:38:25 rh Exp $
#

PKGNAME=	${DISTNAME:C/-/player-/}
COMMONDIR=	../libflash

DEPENDS+=	libflash-*:${COMMONDIR}

PATCHDIR=	${.CURDIR}/${COMMONDIR}/patches
FILESDIR=	${.CURDIR}/${COMMONDIR}/files

do-build:
		cd ${WRKSRC}/Player && make

do-install:
		cd ${WRKSRC}/Player && ${INSTALL_PROGRAM} swfplayer ${PREFIX}/bin

.include "${COMMONDIR}/Makefile.common"
