# $NetBSD: Makefile,v 1.5 2004/01/20 12:25:33 agc Exp $
#

DISTNAME=	AiSSLtelnet-0.15
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://mars.elcom.nitech.ac.jp/security/

MAINTAINER=	tech-pkg@jp.NetBSD.org
HOMEPAGE=	http://mars.elcom.nitech.ac.jp/security/
COMMENT=	SSL Telnet based on AiSSL

GNU_CONFIGURE=	YES

RESTRICTED=             "Source code redistribution is not permitted.consult okuno@mars.elcom.nitech.ac.jp."
NO_SRC_ON_FTP=          ${RESTRICTED}
NO_SRC_ON_CDROM=        ${RESTRICTED}

WRKSRC=         ${WRKDIR}/AiSSLtelnet

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/AiSSLtelnet
	${INSTALL_DATA} ${WRKSRC}/aicrypto/COPYRIGHT ${WRKSRC}/README \
	${WRKSRC}/README-j ${PREFIX}/share/doc/AiSSLtelnet

.include "../../mk/bsd.pkg.mk"
