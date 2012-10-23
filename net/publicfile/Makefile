# $NetBSD: Makefile,v 1.13 2012/10/23 17:19:00 asau Exp $
#

DISTNAME=		publicfile-0.52
CATEGORIES=		net
MASTER_SITES=		http://cr.yp.to/publicfile/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/publicfile.html
COMMENT=		Secure read-only HTTP and FTP servers

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools
DEPENDS+=		ucspi-tcp-[0-9]*:../../net/ucspi-tcp

DJB_RESTRICTED=		YES
DJB_CONFIG_PREFIX=	${PREFIX}/publicfile

SUBST_FILES.djbware+=	leapsecs_read.c

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
