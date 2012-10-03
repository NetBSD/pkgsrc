# $NetBSD: Makefile,v 1.21 2012/10/03 00:02:47 asau Exp $

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
RPM2PKG_PREFIX=		${DESTDIR}${PREFIX}
RPM2PKG_SUBPREFIX=	${EMULSUBDIR}
RPM2PKG_STAGE=		do-install
RPMIGNOREFILES=		./usr

EMUL_YMESSENGER=	${EMULDIR}/opt/ymessenger/bin/ymessenger
YMESSENGER=		${PREFIX}/bin/ymessenger

INSTALLATION_DIRS+=	bin

post-install:
	${SED} '1 s,bin,${EMULSUBDIRSLASH}bin,'				\
		${DESTDIR}${EMUL_YMESSENGER} > ${DESTDIR}${YMESSENGER}
	${CHMOD} 755 ${DESTDIR}${YMESSENGER}

.include "../../mk/bsd.pkg.mk"
