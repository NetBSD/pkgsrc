# $NetBSD: Makefile,v 1.15 2005/01/11 21:09:23 reinoud Exp $
#

DISTNAME=		UDFclient.0.3.2
PKGNAME=		udfclient-0.3.2
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
