# $NetBSD: Makefile,v 1.34 2012/10/06 18:39:18 adam Exp $

DISTNAME=	cfengine-2.2.10
PKGREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.cfengine.org/tarballs/ \
		http://ftp.osuosl.org/pub/cfengine/ \
		ftp://sunsite.uio.no/pub/cfengine/

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://www.cfengine.org/
COMMENT=	Automate configuration and administration of large systems
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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
