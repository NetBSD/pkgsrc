# $NetBSD: Makefile,v 1.4 2001/02/17 18:19:36 wiz Exp $
#

DISTNAME=	sendfile-2.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.uni-stuttgart.de/pub/unix/comm/sendfile/current/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.belwue.de/aktivitaeten/projekte/saft/
COMMENT=	Implementation of the Simple asynchronous file transfer protocol

WRKSRC=	${WRKDIR}/${DISTNAME}

post-patch:
	cd ${WRKSRC} && \
	${SED} -e 's,@PREFIX@,${PREFIX},' < makeconfig > makeconfig.new; \
	${MV} makeconfig.new makeconfig; \
	${CHMOD} +x makeconfig

.include "../../mk/bsd.pkg.mk"
