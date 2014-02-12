# $NetBSD: Makefile,v 1.38 2014/02/12 23:18:38 tron Exp $

DISTNAME=	cfengine-2.2.10
PKGREVISION=	4
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.cfengine.org/tarballs/ \
		http://ftp.osuosl.org/pub/cfengine/ \
		ftp://sunsite.uio.no/pub/cfengine/

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://www.cfengine.org/
COMMENT=	Automate configuration and administration of large systems
LICENSE=	gnu-gpl-v2

BUILD_DEFS+=		IPV6_READY

BDB_ACCEPTED=		db4
USE_LIBTOOL=		yes
USE_TOOLS+=		flex perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-berkeleydb=${BUILDLINK_PREFIX.db4}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

PTHREAD_OPTS+=		require
REPLACE_PERL=		contrib/cfdoc

RCD_SCRIPTS=		cfexecd cfservd cfenvd

INSTALLATION_DIRS=	${PKGMANDIR}/man8 ${VARBASE}/cfengine/inputs

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/*.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
