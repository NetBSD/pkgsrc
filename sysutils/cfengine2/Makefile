# $NetBSD: Makefile,v 1.5 2003/09/16 19:24:25 seb Exp $
#

.include "../../sysutils/cfengine2/Makefile.common"

COMMENT=	Automate configuration and administration of large systems

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

BUILD_DEFS+=		USE_INET6

CONFIGURE_ARGS+=	--with-berkeleydb=${BUILDLINK_PREFIX.db4}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

pre-configure:
	${MV} -f ${WRKSRC}/contrib/vicf.in ${WRKSRC}/contrib/vicf.in.orig
	${SED} -e "s|@ECHO@|${ECHO}|" \
		${WRKSRC}/contrib/vicf.in.orig > ${WRKSRC}/contrib/vicf.in

.include "../../mk/pthread.buildlink2.mk"
.include "../../databases/db4/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
