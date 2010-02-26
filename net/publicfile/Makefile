# $NetBSD: Makefile,v 1.11 2010/02/26 10:28:34 wiz Exp $
#

DISTNAME=		publicfile-0.52
CATEGORIES=		net
MASTER_SITES=		http://cr.yp.to/publicfile/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://cr.yp.to/publicfile.html
COMMENT=		Secure read-only HTTP and FTP servers

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools
DEPENDS+=		ucspi-tcp-[0-9]*:../../net/ucspi-tcp

DJB_RESTRICTED=		YES
DJB_CONFIG_PREFIX=	${PREFIX}/publicfile

SUBST_FILES.djbware+=	leapsecs_read.c

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
