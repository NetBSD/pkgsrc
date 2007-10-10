# $NetBSD: Makefile,v 1.22 2007/10/10 11:11:35 rillig Exp $
#

.include "../../sysutils/cfengine2/Makefile.common"

COMMENT=	Automate configuration and administration of large systems
PKGREVISION=	1

GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

BUILD_DEFS+=		IPV6_READY

CONFIGURE_ARGS+=	--with-berkeleydb=${BUILDLINK_PREFIX.db4}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
USE_TOOLS+=		flex

RCD_SCRIPTS=		cfexecd cfservd cfenvd

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/doc/*.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA_DIR} /var/cfengine/inputs

.include "../../mk/pthread.buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
