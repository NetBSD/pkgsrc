# $NetBSD: Makefile,v 1.2.2.2 2002/06/23 18:55:16 jlam Exp $
#

DISTNAME=	ftpproxy-1.1.5
CATEGORIES=	net
MASTER_SITES=	http://www.ftpproxy.org/download/ \
		ftp://ftp.daemons.de/ \
		http://www.ftpproxy.org/download/older_releases/ \
		ftp://ftp.daemons.de/older_releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	package@netbsd.org
HOMEPAGE=	http://www.ftpproxy.org/
COMMENT=	application level gateway for FTP

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
