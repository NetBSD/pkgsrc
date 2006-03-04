# $NetBSD: Makefile,v 1.11 2006/03/04 21:30:33 jlam Exp $
#

DISTNAME=	ddos_scan
PKGNAME=	ddos-scan-20000325
CATEGORIES=	net security
MASTER_SITES=	http://staff.washington.edu/dittrich/misc/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://staff.washington.edu/dittrich/
COMMENT=	Scan for a limited set of distributed denial of service (ddos) agents

BUILD_TARGET=	default dds

INSTALLATION_DIRS=	sbin share/doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dds ${PREFIX}/sbin/dds
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dds

.include "../../mk/bsd.pkg.mk"
