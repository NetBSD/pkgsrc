# $NetBSD: Makefile,v 1.7 2004/05/04 02:07:06 snj Exp $
#

.include "../../sysutils/cfengine2/Makefile.common"
PKGREVISION=	1

COMMENT=	Automate configuration and administration of large systems

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

BUILD_DEFS+=		USE_INET6

CONFIGURE_ARGS+=	--with-berkeleydb=${BUILDLINK_PREFIX.db4}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

pre-configure:
	${MV} -f ${WRKSRC}/contrib/vicf.in ${WRKSRC}/contrib/vicf.in.orig
	${SED} -e "s|@ECHO@|${ECHO}|" \
		${WRKSRC}/contrib/vicf.in.orig > ${WRKSRC}/contrib/vicf.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
