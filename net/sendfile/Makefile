# $NetBSD: Makefile,v 1.8 2002/10/13 16:30:41 wiz Exp $
#

DISTNAME=	sendfile-20010216
PKGNAME=	sendfile-2.1.0.1
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
