# $NetBSD: Makefile,v 1.1.1.1 2001/09/22 05:38:22 jlam Exp $
#
# FreeBSD Id: ports/misc/bidwatcher/Makefile,v 1.13 2001/04/03 08:14:17 will Exp

DISTNAME=	bidwatcher-1.1.6
CATEGORIES=	misc
MASTER_SITES=	http://www.midwestcs.com/bidwatcher/download/

MAINTAINER=	knotwell@ix.netcom.com
HOMEPAGE=       http://www.midwestcs.com/bidwatcher/
COMMENT=        Ebay snipe tool

USE_GMAKE=	YES
MAKE_ENV+=	OPTIONS="-DHAVE_GMTIME"
MAKE_ENV+=	CXXFLAGS="${CFLAGS} ${CXXFLAGS}"

FILES_SUBST=		BUILDLINK_DIR=${BUILDLINK_DIR}
FILES_SUBST+=		BUILDLINK_X11_DIR=${BUILDLINK_X11_DIR}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

DOCDIR=		${PREFIX}/share/doc/bidwatcher
HTMLDIR=	${PREFIX}/share/doc/html/bidwatcher

post-patch:
	cd ${WRKSRC}; for file in Makefile; do				\
		${SED} ${FILES_SUBST_SED} $${file} >> $${file}.fixed;	\
		${MV} -f $${file}.fixed $${file};			\
	done

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR} ${HTMLDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bidwatcher ${PREFIX}/bin
	cd ${WRKSRC}; ${INSTALL_DATA} README INSTALL CHANGES ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${HTMLDIR}

.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
