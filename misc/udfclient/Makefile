# $NetBSD: Makefile,v 1.10 2004/09/10 13:05:27 reinoud Exp $
#

DISTNAME=		UDFclient.0.3
PKGNAME=		udfclient-0.3
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		http://www.13thmonkey.org/udfclient/releases/
EXTRACT_SUFX=		.tgz

MAINTAINER=		buzztoh@13thmonkey.org
HOMEPAGE=		http://www.13thmonkey.org/udfclient/
COMMENT=		UDF filingsystem reader/writer for CD/CD-RW/DVD*RW/DVD-RAM and images

WRKSRC=			${WRKDIR}/UDFclient.0.3
MAKEFILE=		makefile

PTHREAD_OPTS+=		require

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
