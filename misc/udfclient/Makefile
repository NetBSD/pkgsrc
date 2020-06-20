# $NetBSD: Makefile,v 1.46 2020/06/20 13:29:37 reinoud Exp $
# 

DISTNAME=		UDFclient.0.8.11
PKGNAME=		udfclient-0.8.11
CATEGORIES=		misc
MASTER_SITES=		http://www.13thmonkey.org/udfclient/releases/
EXTRACT_SUFX=		.tgz

MAINTAINER=		reinoud@13thmonkey.org
HOMEPAGE=		http://www.13thmonkey.org/udfclient/
COMMENT=		UDF file system reader/writer for CD/CD-RW/DVD*RW/DVD-RAM and images

GNU_CONFIGURE=		yes

PTHREAD_OPTS+=		require

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	prefix=${PREFIX} \
			mandir=${PREFIX}/${PKGMANDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
