# $NetBSD: Makefile,v 1.3 2000/04/06 23:11:38 wiz Exp $
#

DISTNAME=	ddos_scan
PKGNAME=	ddos-scan-20000325
CATEGORIES=	net security
MASTER_SITES=	http://staff.washington.edu/dittrich/misc/
EXTRACT_SUFX=	.tar

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://staff.washington.edu/dittrich/

DECOMPRESS_CMD=	${CAT}
ALL_TARGET=	default dds

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dds ${PREFIX}/sbin/dds
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dds

.include "../../mk/bsd.pkg.mk"
