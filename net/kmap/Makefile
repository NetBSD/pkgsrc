# $NetBSD: Makefile,v 1.2 2000/04/12 23:09:37 dmcmahill Exp $
#

DISTNAME=	kmap-0.5.6
CATEGORIES=	kde net security
MASTER_SITES=	http://www.islc.net/~icszepp/kmap/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.islc.net/~icszepp/kmap/

DEPENDS+=	kdebase-1.1.2:../../x11/kdebase
DEPENDS+=	nmap-2.12:../../net/nmap

USE_X11BASE=		yes	# To get this near KDE
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=	QTDIR=${X11BASE}/qt1
CONFIGURE_ARGS+=--with-qt-dir=${X11BASE}/qt1

post-patch:
	cd ${WRKSRC}/kmap ; \
	[ -f kmap.cpp.BAK ] || ${MV} kmap.cpp kmap.cpp.BAK ; \
	${SED} \
		-e 's|@LOCALBASE@|${LOCALBASE}|' \
		<kmap.cpp.BAK >kmap.cpp

.include "../../mk/bsd.pkg.mk"
