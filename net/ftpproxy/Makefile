# $NetBSD: Makefile,v 1.7 2004/01/02 17:03:11 taca Exp $
#

DISTNAME=	ftpproxy-1.2.2
CATEGORIES=	net
MASTER_SITES=	http://www.ftpproxy.org/download/ \
		http://www.ftpproxy.org/download/older_releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ftpproxy.org/
COMMENT=	Application level gateway for FTP

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
NROFF?=		nroff
MANDOC?=	-man
LIBS+=		"-lsocket -lnsl"
MAKE_ENV+=	LIBS=${LIBS}
.else
NROFF?=		nroff
MANDOC?=	-mandoc
.endif

post-build:
	cd ${WRKSRC}/doc; ${NROFF} ${MANDOC} ftp.proxy.1 > ftp.proxy.cat8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ftp.proxy ${LOCALBASE}/libexec
	${INSTALL_MAN} ${WRKSRC}/doc/ftp.proxy.cat8 \
		${LOCALBASE}/man/cat8/ftp.proxy.8

.include "../../mk/bsd.pkg.mk"
