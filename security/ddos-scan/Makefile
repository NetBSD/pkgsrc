# $NetBSD: Makefile,v 1.15 2024/07/07 08:55:44 nia Exp $
#

DISTNAME=	ddos_scan
PKGNAME=	ddos-scan-20000325
CATEGORIES=	security net
MASTER_SITES=	http://staff.washington.edu/dittrich/misc/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://staff.washington.edu/dittrich/
COMMENT=	Scan for a limited set of distributed denial of service (ddos) agents

BUILD_TARGET=	default dds

LIBS.SunOS+=	-lresolv -lsocket -lnsl

INSTALLATION_DIRS=	sbin share/doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dds ${DESTDIR}${PREFIX}/sbin/dds
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dds

.include "../../mk/bsd.pkg.mk"
