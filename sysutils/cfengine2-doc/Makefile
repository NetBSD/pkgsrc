# $NetBSD: Makefile,v 1.2 2003/03/28 21:14:34 wiz Exp $
#

PKGNAME=	cfengine-doc-${CFENGINE_VERSION}

.include "../../sysutils/cfengine2/Makefile.common"

COMMENT=	Documentation for cfengine

NO_CONFIGURE=   yes
NO_BUILD=       yes

do-install:
	${INSTALL_MAN_DIR} ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/cfengine.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/doc/cfengine-*.info* ${PREFIX}/info
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/cfengine
	${INSTALL_DATA} ${WRKSRC}/doc/cfengine-*.html ${PREFIX}/share/doc/html/cfengine

post-install:
	${INSTALL_INFO} --info-dir=${PREFIX}/info ${PREFIX}/info/cfengine-Reference.info
	${INSTALL_INFO} --info-dir=${PREFIX}/info ${PREFIX}/info/cfengine-Tutorial.info
	${INSTALL_INFO} --info-dir=${PREFIX}/info ${PREFIX}/info/cfengine-Anomalies.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
