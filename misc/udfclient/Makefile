# $NetBSD: Makefile,v 1.22 2005/06/26 15:24:14 reinoud Exp $
#

DISTNAME=		UDFclient.0.4.9
PKGNAME=		udfclient-0.4.9
#PKGREVISION=		0
CATEGORIES=		misc
MASTER_SITES=		http://www.13thmonkey.org/udfclient/releases/
EXTRACT_SUFX=		.tgz

MAINTAINER=		buzztoh@13thmonkey.org
HOMEPAGE=		http://www.13thmonkey.org/udfclient/
COMMENT=		UDF file system reader/writer for CD/CD-RW/DVD*RW/DVD-RAM and images

GNU_CONFIGURE=		yes

PTHREAD_OPTS+=		require

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
