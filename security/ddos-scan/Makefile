# $NetBSD: Makefile,v 1.17 2026/03/17 08:15:12 nia Exp $

DISTNAME=	ddos_scan
PKGNAME=	ddos-scan-20000325
CATEGORIES=	security net
#MASTER_SITES=	http://staff.washington.edu/dittrich/misc/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://staff.washington.edu/dittrich/
COMMENT=	Scan for a limited set of distributed denial of service (ddos) agents

BUILD_TARGET=	default dds

LDFLAGS.SunOS+=	-lresolv -lsocket -lnsl

INSTALLATION_DIRS=	sbin share/doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dds ${DESTDIR}${PREFIX}/sbin/dds
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dds

.include "../../mk/bsd.pkg.mk"
