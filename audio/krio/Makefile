# $NetBSD: Makefile,v 1.6 2001/05/22 09:32:18 wiz Exp $

DISTNAME=	Krio-19990721
PKGNAME=	krio-19990721
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.13th-floor.org/pub/krio/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=       http://kyle.13th-floor.org/2.0/krio
COMMENT=	kde front-end for managing the Rio PMP300 mp3 player

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_X11BASE=	yes

RIODIR=		${PKGSRCDIR}/audio/rio/${WRKDIR:T}/rio107

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	kdelibs-1.1.2:../../x11/kdelibs
DEPENDS+=	png>=1.0.11:../../graphics/png
DEPENDS+=	qt1-1.44:../../x11/qt1
DEPENDS+=	tiff-*:../../graphics/tiff

WRKSRC=		${WRKDIR}/Krio

EVAL_PREFIX=	QT1DIR=qt1 KDEDIR=kdelibs
MAKE_ENV+=	QT1DIR=${QT1DIR} KDEDIR=${KDEDIR}
MAKE_ENV+=	RIODIR=${RIODIR} X11PREFIX=${X11PREFIX}

pre-configure:
	if [ ! -e ${RIODIR} ]; then					\
		cd ../../audio/rio && ${MAKE} configure;		\
	fi

pre-clean:
	cd ../../audio/rio && ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
