# $NetBSD: Makefile,v 1.8 2004/12/03 15:15:08 wiz Exp $
#

DISTNAME=	ddos_scan
PKGNAME=	ddos-scan-20000325
CATEGORIES=	net security
MASTER_SITES=	http://staff.washington.edu/dittrich/misc/
EXTRACT_SUFX=	.tar

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://staff.washington.edu/dittrich/
COMMENT=	Scan for a limited set of distributed denial of service (ddos) agents

DECOMPRESS_CMD=	${CAT}
BUILD_TARGET=	default dds

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dds ${PREFIX}/sbin/dds
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dds

.include "../../mk/bsd.pkg.mk"
