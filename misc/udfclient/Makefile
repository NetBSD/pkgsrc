# $NetBSD: Makefile,v 1.12 2004/09/11 13:15:34 reinoud Exp $
#

DISTNAME=		UDFclient.0.3
PKGNAME=		udfclient-0.3
PKGREVISION=		2
CATEGORIES=		misc
MASTER_SITES=		http://www.13thmonkey.org/udfclient/releases/
EXTRACT_SUFX=		.tgz

MAINTAINER=		buzztoh@13thmonkey.org
HOMEPAGE=		http://www.13thmonkey.org/udfclient/
COMMENT=		UDF file system reader/writer for CD/CD-RW/DVD*RW/DVD-RAM and images

MAKEFILE=		makefile

USE_BUILDLINK3=		yes
PTHREAD_OPTS+=		require

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
