# $NetBSD: Makefile,v 1.12 2002/04/15 17:40:02 kleink Exp $
#

DISTNAME=		scmxx-0.6.0
CATEGORIES=		comms
MASTER_SITES=		http://www.hendrik-sattler.de/scmxx/download/ \
			http://ma2geo.mathematik.uni-karlsruhe.de/~hendrik/scmxx/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		kleink@netbsd.org
HOMEPAGE=		http://www.hendrik-sattler.de/scmxx/
COMMENT=		Data exchange utility for Siemens mobile phones

GNU_CONFIGURE=		yes
USE_GMAKE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/scmxx
	${INSTALL_DATA} ${WRKSRC}/docs/README				\
	    ${PREFIX}/share/doc/scmxx
	${INSTALL_DATA} ${WRKSRC}/docs/greekchars.txt			\
	    ${PREFIX}/share/doc/scmxx
	${INSTALL_DATA} ${WRKSRC}/docs/gsmcharset.txt			\
	    ${PREFIX}/share/doc/scmxx
	${INSTALL_DATA} ${WRKSRC}/docs/specialchars.txt			\
	    ${PREFIX}/share/doc/scmxx
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/scmxx
	${INSTALL_DATA} ${WRKSRC}/examples/phonebook			\
	    ${PREFIX}/share/examples/scmxx
	${INSTALL_DATA} ${WRKSRC}/examples/sms				\
	    ${PREFIX}/share/examples/scmxx
	${INSTALL_DATA} ${WRKSRC}/examples/vCalendar			\
	    ${PREFIX}/share/examples/scmxx

.include "../../mk/bsd.pkg.mk"
