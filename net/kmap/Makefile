# $NetBSD: Makefile,v 1.13 2003/12/26 19:57:44 wiz Exp $
#

DISTNAME=	kmap-0.5.6
PKGREVISION=	2
CATEGORIES=	kde net security
MASTER_SITES=	http://www.islc.net/~icszepp/kmap/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.islc.net/~icszepp/kmap/
COMMENT=	KDE based frontend for the popular portscanning utility nmap

DEPENDS+=	kdebase-1.1.2nb4:../../x11/kdebase
DEPENDS+=	nmap>=2.12:../../net/nmap

USE_X11BASE=		yes	# To get this near KDE
GNU_CONFIGURE=		yes

EVAL_PREFIX+=	QT1DIR=qt1
CONFIGURE_ENV+=	QTDIR=${QT1DIR}/qt1
CONFIGURE_ARGS+=--with-qt-dir=${QT1DIR}/qt1

post-patch:
	cd ${WRKSRC}/kmap ; \
	[ -f kmap.cpp.BAK ] || ${MV} kmap.cpp kmap.cpp.BAK ; \
	${SED} \
		-e 's|@LOCALBASE@|${LOCALBASE}|' \
		<kmap.cpp.BAK >kmap.cpp

.include "../../mk/bsd.pkg.mk"
