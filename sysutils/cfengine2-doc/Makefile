# $NetBSD: Makefile,v 1.5 2004/09/13 21:12:19 salo Exp $
#

PKGNAME=	cfengine-doc-${CFENGINE_VERSION}
PKGREVISION=	1

.include "../../sysutils/cfengine2/Makefile.common"

COMMENT=	Documentation for cfengine

NO_CONFIGURE=   yes
NO_BUILD=       yes
INFO_FILES=	cfengine-Reference.info cfengine-Tutorial.info
INFO_FILES+=	cfengine-Anomalies.info

do-install:
	${INSTALL_MAN_DIR} ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/*.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/doc/cfengine-*.info* ${PREFIX}/info
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/cfengine
	${INSTALL_DATA} ${WRKSRC}/doc/cfengine-*.html ${PREFIX}/share/doc/html/cfengine

.include "../../mk/bsd.pkg.mk"
