# $NetBSD: Makefile,v 1.19 2016/09/14 06:07:20 mef Exp $
#

DISTNAME=		tcptraceroute-1.4
PKGREVISION=		5
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=mct/}

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		https://github.com/mct/tcptraceroute
COMMENT=		Traceroute implementation using TCP packets
LICENSE=		gnu-gpl-v2

BUILD_TARGET=		tcptraceroute
BUILDLINK_API_DEPENDS.libnet10+=	libnet10>=1.0.2anb1

DOCDIR=			${PREFIX}/share/doc/tcptraceroute

SPECIAL_PERMS+=		sbin/tcptraceroute ${SETUID_ROOT_PERMS}

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-build
SUBST_FILES.conf=	Makefile
SUBST_SED.conf=		-e "s|libnet-config|libnet10-config|g"
SUBST_MESSAGE.conf=	Fixing configuration script.

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin ${DOCDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptraceroute ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tcptraceroute.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/examples.txt ${DESTDIR}${DOCDIR}

.include "../../devel/libnet10/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
