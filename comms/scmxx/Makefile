# $NetBSD: Makefile,v 1.1.1.1 2002/01/13 20:17:33 kleink Exp $
#

DISTNAME=		scmxx-0.5.8
CATEGORIES=		comms
MASTER_SITES=		http://www.hendrik-sattler.de/scmxx/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		kleink@netbsd.org
HOMEPAGE=		http://www.hendrik-sattler.de/scmxx/
COMMENT=		Data exchange utility for Siemens mobile phones

USE_GMAKE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scmxx ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/scmxx.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/scmxx
	${INSTALL_DATA} ${WRKSRC}/docs/README				\
	    ${PREFIX}/share/doc/scmxx
	${INSTALL_DATA} ${WRKSRC}/docs/gsmcharset.txt			\
	    ${PREFIX}/share/doc/scmxx
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/scmxx
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/scmxx/bitmaps
	${INSTALL_DATA} ${WRKSRC}/examples/bitmaps/d1.bmp		\
	    ${PREFIX}/share/examples/scmxx/bitmaps
	${INSTALL_DATA} ${WRKSRC}/examples/bitmaps/d2.bmp		\
	    ${PREFIX}/share/examples/scmxx/bitmaps
	${INSTALL_DATA} ${WRKSRC}/examples/bitmaps/eplus.bmp		\
	    ${PREFIX}/share/examples/scmxx/bitmaps
	${INSTALL_DATA} ${WRKSRC}/examples/bitmaps/viag.bmp		\
	    ${PREFIX}/share/examples/scmxx/bitmaps
	${INSTALL_DATA} ${WRKSRC}/examples/midi				\
	    ${PREFIX}/share/examples/scmxx
	${INSTALL_DATA} ${WRKSRC}/examples/phonebook			\
	    ${PREFIX}/share/examples/scmxx
	${INSTALL_DATA} ${WRKSRC}/examples/sms				\
	    ${PREFIX}/share/examples/scmxx
	${INSTALL_DATA} ${WRKSRC}/examples/vCalendar			\
	    ${PREFIX}/share/examples/scmxx

.include "../../mk/bsd.pkg.mk"
