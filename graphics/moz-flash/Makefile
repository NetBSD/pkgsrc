# $NetBSD: Makefile,v 1.1.1.1 2001/12/01 00:30:34 hubertf Exp $
#

PKGNAME=	moz-flash-1.0

MAINTAINER=	joda@netbsd.org
COMMENT=	Mozilla open source flash(tm) plugin

DEPENDS+=	libflash>=0.4.10nb1:${LIBFLASHDIR}

LIBFLASHDIR=	../../graphics/libflash
PATCHDIR=	${.CURDIR}/${LIBFLASHDIR}/patches
FILESDIR=	${.CURDIR}/${LIBFLASHDIR}/files
DISTINFO_FILE=	${.CURDIR}/${LIBFLASHDIR}/distinfo

DEPENDS+=	mozilla-[0-9]*:../mozilla

USE_X11BASE=	yes

MOZ_PLUGDIR=     ${X11PREFIX}/lib/mozilla/plugins

do-build:
		cd ${WRKSRC}/Plugin && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
		cd ${WRKSRC}/Plugin && ${INSTALL_PROGRAM} npflash.so ${MOZ_PLUGDIR}

.include "${LIBFLASHDIR}/Makefile.common"
