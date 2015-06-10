# $NetBSD: Makefile,v 1.18 2015/06/10 14:40:07 fhajny Exp $
#

DISTNAME=		pdns-recursor-3.7.3
CATEGORIES=		net
MASTER_SITES=		http://downloads.powerdns.com/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.powerdns.com/
COMMENT=		PowerDNS resolver/recursing nameserver
LICENSE=		gnu-gpl-v2

HAS_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

RCD_SCRIPTS+=		pdns_recursor

EGDIR=			${PREFIX}/share/examples/pdns-recursor

BUILD_MAKE_FLAGS+=	SYSCONFDIR=${PKG_SYSCONFDIR} OPTFLAGS=

INSTALL_MAKE_FLAGS+=	BINDIR=${PREFIX}/bin SBINDIR=${PREFIX}/sbin
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR} MANDIR=${PREFIX}/${PKGMANDIR}

CONF_FILES+=		${EGDIR}/recursor.conf-dist \
			${PKG_SYSCONFDIR}/recursor.conf

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-std=c++11 -Wno-c++11-narrowing
.endif

.include "options.mk"

post-extract:
	${LN} -s FreeBSD.inc ${WRKSRC}/sysdeps/NetBSD.inc

post-build:
	${CP} ${WRKSRC}/pdns_recursor.1 ${WRKSRC}/pdns_recursor.8
	${CP} ${WRKSRC}/rec_control.1 ${WRKSRC}/rec_control.8

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
