# $NetBSD: Makefile,v 1.5 2001/12/02 14:47:13 tron Exp $
#

PKGNAME=	${DISTNAME:C/-/player-/}
COMMONDIR=	../libflash

DEPENDS+=	libflash-[0-9]*:${COMMONDIR}

COMMENT=	standalone open source flash(tm) player

DISTINFO_FILE=	${.CURDIR}/${COMMONDIR}/distinfo
FILESDIR=	${.CURDIR}/${COMMONDIR}/files
PATCHDIR=	${.CURDIR}/${COMMONDIR}/patches

do-build:
		cd ${WRKSRC}/Player && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
		cd ${WRKSRC}/Player && ${INSTALL_PROGRAM} swfplayer ${PREFIX}/bin

.include "${COMMONDIR}/Makefile.common"
