# $NetBSD: Makefile,v 1.3 2001/09/27 23:18:10 jlam Exp $
#

PKGNAME=	${DISTNAME:C/-/player-/}
COMMONDIR=	../libflash

DEPENDS+=	libflash-[0-9]*:${COMMONDIR}

COMMENT=	standalone open source flash(tm) player

PATCHDIR=	${.CURDIR}/${COMMONDIR}/patches
FILESDIR=	${.CURDIR}/${COMMONDIR}/files

do-build:
		cd ${WRKSRC}/Player && make

do-install:
		cd ${WRKSRC}/Player && ${INSTALL_PROGRAM} swfplayer ${PREFIX}/bin

.include "${COMMONDIR}/Makefile.common"
