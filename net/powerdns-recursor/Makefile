# $NetBSD: Makefile,v 1.48 2025/06/30 11:06:46 jperkin Exp $

DISTNAME=	pdns-recursor-4.9.9
PKGNAME=	${DISTNAME:S/pdns/powerdns/}
CATEGORIES=	net
MASTER_SITES=	http://downloads.powerdns.com/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.powerdns.com/
COMMENT=	PowerDNS resolver/recursing nameserver
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-net-snmp

# currently not portable
CONFIGURE_ENV.NetBSD+=	ac_cv_search_pthread_setaffinity_np=no

RCD_SCRIPTS=		pdns_recursor

SMF_NAME=		pdns-recursor
SMF_METHODS=		pdns_recursor

EGDIR=			${PREFIX}/share/examples/pdns-recursor

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

CONF_FILES+=		${EGDIR}/recursor.conf-dist \
			${PKG_SYSCONFDIR}/recursor.conf

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-Wno-c++11-narrowing
.endif

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
