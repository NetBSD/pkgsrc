# $NetBSD: Makefile,v 1.18 2013/02/06 19:31:02 jperkin Exp $
#

DISTNAME=		tcptraceroute-1.4
PKGREVISION=		5
CATEGORIES=		net
MASTER_SITES=		http://michael.toren.net/code/tcptraceroute/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://michael.toren.net/code/tcptraceroute/
COMMENT=		Traceroute implementation using TCP packets

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
