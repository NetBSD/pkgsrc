# $NetBSD: Makefile,v 1.21 2022/12/15 12:15:01 jperkin Exp $
#

DISTNAME=		tcptraceroute-1.4
PKGREVISION=		5
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=mct/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/mct/tcptraceroute
COMMENT=		Traceroute implementation using TCP packets
LICENSE=		gnu-gpl-v2

BUILD_TARGET=		tcptraceroute
BUILDLINK_API_DEPENDS.libnet10+=	libnet10>=1.0.2anb1

DOCDIR=			${PREFIX}/share/doc/tcptraceroute

SPECIAL_PERMS+=		sbin/tcptraceroute ${SETUID_ROOT_PERMS}

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin ${DOCDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptraceroute ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tcptraceroute.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/examples.txt ${DESTDIR}${DOCDIR}

.include "../../devel/libnet10/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
