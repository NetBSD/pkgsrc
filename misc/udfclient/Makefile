# $NetBSD: Makefile,v 1.11 2004/09/10 13:09:28 wiz Exp $
#

DISTNAME=		UDFclient.0.3
PKGNAME=		udfclient-0.3
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		http://www.13thmonkey.org/udfclient/releases/
EXTRACT_SUFX=		.tgz

MAINTAINER=		buzztoh@13thmonkey.org
HOMEPAGE=		http://www.13thmonkey.org/udfclient/
COMMENT=		UDF file system reader/writer for CD/CD-RW/DVD*RW/DVD-RAM and images

MAKEFILE=		makefile

PTHREAD_OPTS+=		require

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
