# $NetBSD: Makefile,v 1.48 2018/08/22 09:46:31 wiz Exp $

DISTNAME=	cfengine-2.2.10
PKGREVISION=	10
CATEGORIES=	sysutils net
#MASTER_SITES=	http://www.cfengine.org/tarballs/
MASTER_SITES+=	http://ftp.osuosl.org/pub/cfengine/
MASTER_SITES+=	ftp://sunsite.uio.no/pub/cfengine/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.cfengine.org/
COMMENT=	Automate configuration and administration of large systems
LICENSE=	gnu-gpl-v2

BUILD_DEFS+=		IPV6_READY

BDB_ACCEPTED=		db4
USE_LIBTOOL=		yes
USE_TOOLS+=		flex perl:run yacc
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-berkeleydb=${BUILDLINK_PREFIX.db4}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

PTHREAD_OPTS+=		require
REPLACE_PERL=		contrib/cfdoc

RCD_SCRIPTS=		cfexecd cfservd cfenvd

OWN_DIRS=		${VARBASE}/cfengine
OWN_DIRS+=		${VARBASE}/cfengine/inputs

INSTALLATION_DIRS=	${PKGMANDIR}/man8

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/*.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
