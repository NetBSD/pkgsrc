# $NetBSD: Makefile,v 1.19 2009/05/19 08:59:05 wiz Exp $

DISTNAME=		rh9.ymessenger-1.0.4-1.i386
PKGNAME=		ymessenger-1.0.4
CATEGORIES=		chat
MASTER_SITES=		http://download.yahoo.com/dl/unix/
EXTRACT_SUFX=		.rpm

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://messenger.yahoo.com/
COMMENT=		Yahoo! instant messaging client
LICENSE=		generic-nonlicense

RESTRICTED=		Commercial software (no permission to copy is evident).
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	compat gtk gdk-pixbuf

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

EMUL_PKG_FMT=		rpm
RPM2PKG_PREFIX=		${PREFIX}
RPM2PKG_SUBPREFIX=	${EMULSUBDIR}
RPM2PKG_STAGE=		do-install
RPMIGNOREFILES=		./usr

EMUL_YMESSENGER=	${EMULDIR}/opt/ymessenger/bin/ymessenger
YMESSENGER=		${PREFIX}/bin/ymessenger

post-install:
	${SED} '1 s,bin,${EMULSUBDIRSLASH}bin,'				\
		${EMUL_YMESSENGER} > ${YMESSENGER}
	${CHMOD} 755 ${YMESSENGER}

.include "../../mk/bsd.pkg.mk"
