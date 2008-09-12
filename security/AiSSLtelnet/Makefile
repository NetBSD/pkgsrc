# $NetBSD: Makefile,v 1.11 2008/09/12 11:42:02 gdt Exp $
#

DISTNAME=	AiSSLtelnet-0.15
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://mars.elcom.nitech.ac.jp/security/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://mars.elcom.nitech.ac.jp/security/
COMMENT=	SSL Telnet based on AiSSL

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

# License unreadable due to unfetchable distfile.
LICENSE=		generic-nonlicense
RESTRICTED=		Source code redistribution is not permitted.consult okuno@mars.elcom.nitech.ac.jp.
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/AiSSLtelnet

INSTALLATION_DIRS=	share/doc/AiSSLtelnet
INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}

pre-install:
	${INSTALL_DATA} ${WRKSRC}/aicrypto/COPYRIGHT ${WRKSRC}/README \
	${WRKSRC}/README-j ${DESTDIR}${PREFIX}/share/doc/AiSSLtelnet

# The sources assume <malloc.h> exists.  Create a fake one for platforms
# that don't have it.
post-wrapper:
	if ${TEST} ! -f /usr/include/malloc.h; then		\
		${ECHO} "#include <stdlib.h>"			\
			> ${BUILDLINK_DIR}/include/malloc.h;	\
	fi

.include "../../mk/bsd.pkg.mk"
