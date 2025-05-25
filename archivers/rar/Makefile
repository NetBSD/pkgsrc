# $NetBSD: Makefile,v 1.59 2025/05/25 06:08:30 vins Exp $

DISTNAME=	rarlinux${EMUL_PLATFORM:S|linux-x86_64|-x64|:S|linux-i386|-x32|}-${PKGVERSION_NOREV:S/.//}
PKGNAME=	rar-7.11
CATEGORIES=	archivers
MASTER_SITES=	http://www.rarlabs.com/rar/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.rarlabs.com/
COMMENT=	RAR file archiver (binary)
LICENSE=	rar-license

RESTRICTED=		Only unmodified original package can be distributed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

EMUL_PLATFORMS=		linux-x86_64
EMUL_MODULES.linux=	base

USE_LANGUAGES=	# none

DOCDIR=		share/doc/${PKGBASE}
EGDIR=		share/examples/${PKGBASE}
CONF_FILES+=	${EGDIR}/rarfiles.lst ${PKG_SYSCONFDIR}/rarfiles.lst

PKG_DOCS=	acknow.txt readme.txt whatsnew.txt

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/rar

INSTALLATION_DIRS=	bin etc lib ${DOCDIR} ${EGDIR} ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar ${DESTDIR}${PREFIX}/bin/rar
	${INSTALL_LIB} ${WRKSRC}/default.sfx ${DESTDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/rar.txt		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rar.1
	${INSTALL_DATA} ${PKG_DOCS:S|^|${WRKSRC}/|}	\
		${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${DESTDIR}${PREFIX}/${EGDIR}
.include "../../mk/bsd.pkg.mk"
