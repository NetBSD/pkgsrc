# $NetBSD: Makefile,v 1.14 2003/10/08 10:06:47 taca Exp $

DISTNAME=	Krio-19990721
PKGNAME=	krio-19990721
PKGREVISION=	1
WRKSRC=		${WRKDIR}/Krio
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.13th-floor.org/pub/krio/

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=       http://kyle.13th-floor.org/2.0/krio
COMMENT=	KDE front-end for managing the Rio PMP300 mp3 player

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_X11BASE=	yes

RIODIR=		${_PKGSRCDIR}/audio/rio/${WRKDIR:T}/rio107

DEPENDS+=	jpeg>=6b:../../graphics/jpeg
DEPENDS+=	kdelibs-1.1.2nb1:../../x11/kdelibs
DEPENDS+=	png>=1.2.1:../../graphics/png
DEPENDS+=	qt1-1.44:../../x11/qt1
DEPENDS+=	tiff-[0-9]*:../../graphics/tiff

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
