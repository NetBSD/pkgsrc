# $NetBSD: Makefile,v 1.4 2001/02/17 17:49:42 wiz Exp $
#

DISTNAME=	ddos_scan
PKGNAME=	ddos-scan-20000325
CATEGORIES=	net security
MASTER_SITES=	http://staff.washington.edu/dittrich/misc/
EXTRACT_SUFX=	.tar

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://staff.washington.edu/dittrich/
COMMENT=	scan for a limited set of distributed denial of service (ddos) agents

DECOMPRESS_CMD=	${CAT}
ALL_TARGET=	default dds

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dds ${PREFIX}/sbin/dds
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dds

.include "../../mk/bsd.pkg.mk"
