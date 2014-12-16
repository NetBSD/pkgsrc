# $NetBSD: Makefile,v 1.14.4.1 2014/12/16 23:23:22 tron Exp $
#

DISTNAME=		pdns-recursor-3.3
PKGREVISION=		5
CATEGORIES=		net
MASTER_SITES=		http://downloads.powerdns.com/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.powerdns.com/
COMMENT=		PowerDNS resolver/recursing nameserver
LICENSE=		gnu-gpl-v2

MAKE_JOBS_SAFE=		no

USE_TOOLS=		gmake
USE_LANGUAGES=		c c++

RCD_SCRIPTS+=		pdns_recursor

EGDIR=			${PREFIX}/share/examples/pdns-recursor

BUILD_MAKE_FLAGS+=	CONFIGDIR=${PKG_SYSCONFDIR} OPTFLAGS=

INSTALL_MAKE_FLAGS+=	BINDIR=${PREFIX}/bin SBINDIR=${PREFIX}/sbin
INSTALL_MAKE_FLAGS+=	CONFIGDIR=${EGDIR} MANDIR=${PREFIX}/${PKGMANDIR}

CONF_FILES+=		${EGDIR}/recursor.conf-dist \
			${PKG_SYSCONFDIR}/recursor.conf

SUBST_CLASSES+=			whitespace
SUBST_STAGE.whitespace=		pre-configure
SUBST_MESSAGE.whitespace=	Fixing C++ semantic whitespace.
SUBST_FILES.whitespace=		pdns_recursor.cc
SUBST_SED.whitespace=		-e 's|"VERSION"|" VERSION "|'

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-std=c++11 -Wno-c++11-narrowing
.endif

.include "options.mk"

post-patch:
	${SED} -e "s:/etc/powerdns:${PKG_SYSCONFDIR}:" \
		${WRKSRC}/config.h >${WRKSRC}/config.h.new
	${MV} ${WRKSRC}/config.h.new ${WRKSRC}/config.h
	${LN} -s FreeBSD.inc ${WRKSRC}/sysdeps/NetBSD.inc
	${MV} ${WRKSRC}/pdns_recursor.1 ${WRKSRC}/pdns_recursor.8
	${MV} ${WRKSRC}/rec_control.1 ${WRKSRC}/rec_control.8

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
