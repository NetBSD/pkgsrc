# $NetBSD: Makefile,v 1.12 2004/10/03 00:18:14 tv Exp $
#

PKGREVISION=	1

.include "../../sysutils/cfengine2/Makefile.common"

COMMENT=	Automate configuration and administration of large systems

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

BUILD_DEFS+=		USE_INET6

CONFIGURE_ARGS+=	--with-berkeleydb=${BUILDLINK_PREFIX.db4}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

USE_PKGINSTALL=		YES
RCD_SCRIPTS=		cfexecd cfservd cfenvd

pre-configure:
	${MV} -f ${WRKSRC}/contrib/vicf.in ${WRKSRC}/contrib/vicf.in.orig
	${SED} -e "s|@ECHO@|${ECHO}|" \
		${WRKSRC}/contrib/vicf.in.orig > ${WRKSRC}/contrib/vicf.in

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/*.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/inputs/*.example \
		${PREFIX}/share/examples/cfengine
	${INSTALL_DATA_DIR} /var/cfengine/inputs

.include "../../mk/pthread.buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
