# $NetBSD: Makefile,v 1.20 2017/03/24 18:45:44 fhajny Exp $
#

DISTNAME=		pdns-recursor-4.0.4
CATEGORIES=		net
MASTER_SITES=		http://downloads.powerdns.com/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.powerdns.com/
COMMENT=		PowerDNS resolver/recursing nameserver
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config

RCD_SCRIPTS+=		pdns_recursor

EGDIR=			${PREFIX}/share/examples/pdns-recursor

PTHREAD_AUTO_VARS=	yes

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

CONF_FILES+=		${EGDIR}/recursor.conf-dist \
			${PKG_SYSCONFDIR}/recursor.conf

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-std=c++11 -Wno-c++11-narrowing
.endif

.include "options.mk"

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
