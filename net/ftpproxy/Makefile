# $NetBSD: Makefile,v 1.8 2005/03/14 19:55:39 tv Exp $
#

DISTNAME=	ftpproxy-1.2.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.ftpproxy.org/download/ \
		http://www.ftpproxy.org/download/older_releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ftpproxy.org/
COMMENT=	Application level gateway for FTP

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LIBS+=		"-lsocket -lnsl"
MAKE_ENV+=	LIBS=${LIBS}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ftp.proxy ${PREFIX}/libexec/
	${INSTALL_MAN} ${WRKSRC}/doc/ftp.proxy.1 ${PREFIX}/man/man8/ftp.proxy.8

.include "../../mk/bsd.pkg.mk"
