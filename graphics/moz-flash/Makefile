# $NetBSD: Makefile,v 1.3 2001/12/01 01:42:20 lukem Exp $
#

PKGNAME=	moz-flash-1.0

MAINTAINER=	joda@netbsd.org
COMMENT=	Mozilla open source flash(tm) plugin

LIBFLASHDIR=	../../graphics/libflash
PATCHDIR=	${.CURDIR}/${LIBFLASHDIR}/patches
FILESDIR=	${.CURDIR}/${LIBFLASHDIR}/files
DISTINFO_FILE=	${.CURDIR}/${LIBFLASHDIR}/distinfo

DEPENDS+=	libflash>=0.4.10nb1:${LIBFLASHDIR}
DEPENDS+=	mozilla-[0-9]*:../../www/mozilla

USE_X11BASE=	yes

MOZ_PLUGDIR=     ${X11PREFIX}/lib/mozilla/plugins

do-build:
		cd ${WRKSRC}/Plugin && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
		cd ${WRKSRC}/Plugin && ${INSTALL_PROGRAM} npflash.so ${MOZ_PLUGDIR}

.include "${LIBFLASHDIR}/Makefile.common"
