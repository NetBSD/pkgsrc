# $NetBSD: Makefile,v 1.9 2005/03/23 00:51:10 schmonz Exp $
#

DISTNAME=		publicfile-0.52
CATEGORIES=		net
MASTER_SITES=		http://cr.yp.to/publicfile/

MAINTAINER=		zuntum@NetBSD.org
HOMEPAGE=		http://cr.yp.to/publicfile.html
COMMENT=		Secure read-only HTTP and FTP servers

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools
DEPENDS+=		ucspi-tcp-[0-9]*:../../net/ucspi-tcp

DJB_RESTRICTED=		YES
DJB_CONFIG_PREFIX=	${PREFIX}/publicfile

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
