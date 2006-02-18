# $NetBSD: Makefile,v 1.12 2006/02/18 13:31:28 rillig Exp $
#

DISTNAME=	ftpproxy-${VERSION}
CATEGORIES=	net
MASTER_SITES=	http://www.ftpproxy.org/download/ \
		http://www.ftpproxy.org/download/older_releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ftpproxy.org/
COMMENT=	Application level gateway for FTP

BUILD_DIRS=	src
VERSION=	1.2.3

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LIBS+=		-lsocket -lnsl
OSFLAG=		-DSOLARIS
.endif
MAKE_ENV+=	OSFLAG=${OSFLAG:Q} OSLIB=${LIBS:M*:Q} VERSION=${VERSION:Q}

INSTALLATION_DIRS=	libexec man/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/src/ftp.proxy ${PREFIX:Q}/libexec/
	${INSTALL_MAN} ${WRKSRC:Q}/doc/ftp.proxy.1 ${PREFIX:Q}/man/man8/ftp.proxy.8

.include "../../mk/bsd.pkg.mk"
