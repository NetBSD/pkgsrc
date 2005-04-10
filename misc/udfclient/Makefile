# $NetBSD: Makefile,v 1.18 2005/04/10 00:42:49 reinoud Exp $
#

DISTNAME=		UDFclient.0.3.5
PKGNAME=		udfclient-0.3.5
#PKGREVISION=		0
CATEGORIES=		misc
MASTER_SITES=		http://www.13thmonkey.org/udfclient/releases/
EXTRACT_SUFX=		.tgz

MAINTAINER=		buzztoh@13thmonkey.org
HOMEPAGE=		http://www.13thmonkey.org/udfclient/
COMMENT=		UDF file system reader/writer for CD/CD-RW/DVD*RW/DVD-RAM and images

GNU_CONFIGURE=		yes

USE_BUILDLINK3=		yes
PTHREAD_OPTS+=		require

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
