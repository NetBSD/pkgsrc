# $NetBSD: Makefile,v 1.1.1.1 2000/11/17 13:09:54 agc Exp $
#

DISTNAME=	Krio-19990721
PKGNAME=	krio-19990721
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.13th-floor.org/pub/krio/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=       http://kyle.13th-floor.org/2.0/krio

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_X11=	yes

RIODIR=		${PKGSRCDIR}/audio/rio/${WRKDIR:T}/rio107

BUILD_DEPENDS+=	${RIODIR}/rio.cpp:../../audio/rio:configure

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	kdelibs-1.1.2:../../x11/kdelibs
DEPENDS+=	png-*:../../graphics/png
DEPENDS+=	qt1-1.44:../../x11/qt1
DEPENDS+=	tiff-*:../../graphics/tiff

WRKSRC=		${WRKDIR}/Krio

EVAL_PREFIX=	QT1DIR=qt1 KDEDIR=kdelibs
MAKE_ENV+=	QT1DIR=${QT1DIR} KDEDIR=${KDEDIR}
MAKE_ENV+=	RIODIR=${RIODIR} X11PREFIX=${X11PREFIX}

.include "../../mk/bsd.pkg.mk"
