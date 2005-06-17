# $NetBSD: Makefile,v 1.7 2005/06/17 03:50:33 jlam Exp $
#

PKGNAME=	cfengine-doc-${CFENGINE_VERSION}
PKGREVISION=	1

.include "../../sysutils/cfengine2/Makefile.common"

COMMENT=	Documentation for cfengine

NO_CONFIGURE=   yes
NO_BUILD=       yes
INFO_FILES=	cfengine-Reference.info cfengine-Tutorial.info
INFO_FILES+=	cfengine-Anomalies.info

INSTALLATION_DIRS=	info

do-install:
	${INSTALL_DATA} ${WRKSRC}/doc/cfengine-*.info* ${PREFIX}/info
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/cfengine
	${INSTALL_DATA} ${WRKSRC}/doc/cfengine-*.html ${PREFIX}/share/doc/html/cfengine

.include "../../mk/bsd.pkg.mk"
