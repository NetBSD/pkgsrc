# $NetBSD: Makefile,v 1.1.1.1 2002/12/22 13:04:38 seb Exp $
#

.include "../../sysutils/cfengine2/Makefile.common"

COMMENT=	Automate configuration and administration of large systems

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

CONFIGURE_ARGS+=	--with-berkeleydb=${BUILDLINK_PREFIX.db4}

pre-configure:
	${MV} -f ${WRKSRC}/contrib/vicf.in ${WRKSRC}/contrib/vicf.in.orig
	${SED} -e "s|@ECHO@|${ECHO}|" \
		${WRKSRC}/contrib/vicf.in.orig > ${WRKSRC}/contrib/vicf.in

.include "../../mk/pthread.buildlink2.mk"
.include "../../databases/db4/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
