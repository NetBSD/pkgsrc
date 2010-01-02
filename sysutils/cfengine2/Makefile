# $NetBSD: Makefile,v 1.28 2010/01/02 10:55:05 sekiya Exp $
#

DISTNAME=		cfengine-2.2.8
PKGREVISION=	2
CATEGORIES=		sysutils net
MASTER_SITES=		http://www.cfengine.org/downloads/ \
			http://ftp.osuosl.org/pub/cfengine/ \
			ftp://sunsite.uio.no/pub/cfengine/
MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://www.cfengine.org/
COMMENT=		Automate configuration and administration of large systems

GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require
BUILD_DEFS+=		IPV6_READY

CONFIGURE_ARGS+=	--with-berkeleydb=${BUILDLINK_PREFIX.db4}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
USE_TOOLS+=		flex perl:run
USE_LIBTOOL=		yes
REPLACE_PERL=		contrib/cfdoc
PKG_DESTDIR_SUPPORT=	user-destdir

RCD_SCRIPTS=		cfexecd cfservd cfenvd

post-install:
	${INSTALL_MAN_DIR} ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/doc/*.8 ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA_DIR} ${DESTDIR}/var/cfengine/inputs

.include "../../mk/pthread.buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
