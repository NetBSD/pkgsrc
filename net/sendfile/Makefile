# $NetBSD: Makefile,v 1.9 2002/10/17 19:18:01 wiz Exp $
#

DISTNAME=	sendfile-20010216
PKGNAME=	sendfile-2.1.0.2
WRKSRC=		${WRKDIR}/sendfile-2.1a
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.belwue.de/pub/unix/sendfile/current/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.belwue.de/aktivitaeten/projekte/saft/
COMMENT=	Implementation of the Simple asynchronous file transfer protocol

post-patch:
	cd ${WRKSRC} && \
	${SED} -e 's,@PREFIX@,${PREFIX},' < makeconfig > makeconfig.new; \
	${MV} makeconfig.new makeconfig; \
	${CHMOD} +x makeconfig

post-configure:
	cd ${WRKSRC} && ${MAKE} config

.include "../../mk/bsd.pkg.mk"
