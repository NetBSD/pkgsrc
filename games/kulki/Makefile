# $NetBSD: Makefile,v 1.1.1.1 2001/03/12 08:57:37 zuntum Exp $
#

DISTNAME=	kulki-1.01
CATEGORIES=	games
MASTER_SITES=	http://www.cs.put.poznan.pl/adanilecki/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.cs.put.poznan.pl/adanilecki/
COMMENT=	Simple logic game - "balls"

DEPENDS+=	qt2>=2.2.3:../../x11/qt2
DEPENDS+=	png-*:../../graphics/png

WRKSRC=		${WRKDIR}/kulki

USE_GMAKE=	YES

MAKE_ENV=	"MOC=${X11BASE}/qt2/bin/moc"			\
		"CXX=${CXX}"					\
		"CP=${CP}"					\
		"QTDIR=${X11BASE}/qt2"				\
		"CXXFLAGS=${CXXFLAGS}"

post-patch:
	${SED}	-e "s,@X11BASE@,${X11BASE},g"			\
		-e "s,@PREFIX@,${PREFIX},g"			\
		-e "s,@LOCALBASE@,${LOCALBASE},g"		\
		${WRKSRC}/Makefile > ${WRKSRC}/Makefile.done
	${MV} ${WRKSRC}/Makefile.done ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/kulki
	${INSTALL_PROGRAM} ${WRKSRC}/kulki ${PREFIX}/bin
	cd ${WRKSRC} &&						\
	${INSTALL_DATA} BUGS CHANGES FAQ README README.PL TODO	\
		help.html pomoc.html ${PREFIX}/share/kulki
	cd ${PREFIX}/share/kulki &&				\
		( ${GUNZIP_CMD} -c ${WRKSRC}/images.tgz | ${GTAR} xf - )

.include "../../mk/bsd.pkg.mk"
