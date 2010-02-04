# $NetBSD: Makefile,v 1.40 2010/02/04 17:19:34 joerg Exp $
#

DISTNAME=		UDFclient.0.7.1
PKGNAME=		udfclient-0.7.1
#PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		http://www.13thmonkey.org/udfclient/releases/
EXTRACT_SUFX=		.tgz

MAINTAINER=		reinoud@13thmonkey.org
HOMEPAGE=		http://www.13thmonkey.org/udfclient/
COMMENT=		UDF file system reader/writer for CD/CD-RW/DVD*RW/DVD-RAM and images

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

PTHREAD_OPTS+=		require

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
