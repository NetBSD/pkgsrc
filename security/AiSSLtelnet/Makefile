# $NetBSD: Makefile,v 1.9 2008/05/17 08:22:56 obache Exp $
#

DISTNAME=	AiSSLtelnet-0.15
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://mars.elcom.nitech.ac.jp/security/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://mars.elcom.nitech.ac.jp/security/
COMMENT=	SSL Telnet based on AiSSL

GNU_CONFIGURE=	YES

RESTRICTED=		Source code redistribution is not permitted.consult okuno@mars.elcom.nitech.ac.jp.
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/AiSSLtelnet

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/AiSSLtelnet
	${INSTALL_DATA} ${WRKSRC}/aicrypto/COPYRIGHT ${WRKSRC}/README \
	${WRKSRC}/README-j ${PREFIX}/share/doc/AiSSLtelnet

# The sources assume <malloc.h> exists.  Create a fake one for platforms
# that don't have it.
post-wrapper:
	if ${TEST} ! -f /usr/include/malloc.h; then		\
		${ECHO} "#include <stdlib.h>"			\
			> ${BUILDLINK_DIR}/include/malloc.h;	\
	fi

.include "../../mk/bsd.pkg.mk"
