# $NetBSD: Makefile,v 1.4 2003/09/21 08:53:35 jmc Exp $
#

DISTNAME=	AiSSLtelnet-0.15
PKGREVISION=	1
WRKSRC=         ${WRKDIR}/AiSSLtelnet
CATEGORIES=	security
MASTER_SITES=	http://mars.elcom.nitech.ac.jp/security/

MAINTAINER=	tech-pkg@jp.NetBSD.org
HOMEPAGE=	http://mars.elcom.nitech.ac.jp/security/
COMMENT=	SSL Telnet based on AiSSL

GNU_CONFIGURE=	YES

RESTRICTED=             "Source code redistribution is not permitted.consult okuno@mars.elcom.nitech.ac.jp."
NO_SRC_ON_FTP=          ${RESTRICTED}
NO_SRC_ON_CDROM=        ${RESTRICTED}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/AiSSLtelnet
	${INSTALL_DATA} ${WRKSRC}/aicrypto/COPYRIGHT ${WRKSRC}/README \
	${WRKSRC}/README-j ${PREFIX}/share/doc/AiSSLtelnet

.include "../../mk/bsd.pkg.mk"
