# $NetBSD: Makefile,v 1.8 2013/02/06 23:23:48 jperkin Exp $
#

DISTNAME=	cfengine-3.1.4
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://cfengine.com/source-code/download?file=

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://cfengine.com/pages/community
COMMENT=	Tool for automating system administration
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		flex yacc gmake

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-berkeleydb=${BUILDLINK_PREFIX.db4:Q}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl:Q}
CONFIGURE_ARGS+=	--with-pcre=${BUILDLINK_PREFIX.pcre:Q}

BUILD_DEFS+=		${VARBASE}
BUILDLINK_TRANSFORM+=l:db:db4

EGDIR=			${PREFIX}/share/examples/cfengine
SYSCONFDIR=		${PKG_SYSCONFDIR}/cfengine

CONF_FILES+=		${EGDIR}/inputs/cfengine_stdlib.cf ${SYSCONFDIR}/cfengine_stdlib.cf
CONF_FILES+=		${EGDIR}/inputs/failsafe.cf ${SYSCONFDIR}/failsafe.cf
CONF_FILES+=		${EGDIR}/inputs/promises.cf ${SYSCONFDIR}/promises.cf
CONF_FILES+=		${EGDIR}/inputs/site.cf ${SYSCONFDIR}/site.cf
CONF_FILES+=		${EGDIR}/inputs/update.cf ${SYSCONFDIR}/update.cf

RCD_SCRIPTS=		cfserverd cfexecd cfmonitord

INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} sysconfdir=${SYSCONFDIR:Q} inputsdir=${EGDIR:Q}/inputs

MAKE_DIRS=		${VARBASE}/cfengine
INSTALLATION_DIRS=	${EGDIR}/inputs ${SYSCONFDIR}

.include "../../databases/db4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
