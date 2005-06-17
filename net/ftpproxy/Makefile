# $NetBSD: Makefile,v 1.10 2005/06/17 03:50:25 jlam Exp $
#

DISTNAME=	ftpproxy-${VERSION}
CATEGORIES=	net
MASTER_SITES=	http://www.ftpproxy.org/download/ \
		http://www.ftpproxy.org/download/older_releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ftpproxy.org/
COMMENT=	Application level gateway for FTP

BUILD_DIRS=	${WRKSRC}/src
VERSION=	1.2.3

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LIBS+=		"-lsocket -lnsl"
OSFLAG=		-DSOLARIS
.endif
MAKE_ENV+=	OSFLAG=${OSFLAG} OSLIB=${LIBS} VERSION=${VERSION}

INSTALLATION_DIRS=	libexec man/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ftp.proxy ${PREFIX}/libexec/
	${INSTALL_MAN} ${WRKSRC}/doc/ftp.proxy.1 ${PREFIX}/man/man8/ftp.proxy.8

.include "../../mk/bsd.pkg.mk"
