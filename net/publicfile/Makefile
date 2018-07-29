# $NetBSD: Makefile,v 1.15 2018/07/29 23:46:21 schmonz Exp $
#

DISTNAME=		publicfile-0.52
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://cr.yp.to/publicfile/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/publicfile.html
COMMENT=		Secure read-only HTTP and FTP servers

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools

DJB_RESTRICTED=		YES
DJB_CONFIG_PREFIX=	${PREFIX}/publicfile

SUBST_FILES.djbware+=	leapsecs_read.c

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
