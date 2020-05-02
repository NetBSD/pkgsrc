# $NetBSD: Makefile,v 1.17 2020/05/02 13:44:55 rillig Exp $
#

DISTNAME=		publicfile-0.52
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://cr.yp.to/publicfile/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://cr.yp.to/publicfile.html
COMMENT=		Secure read-only HTTP and FTP servers

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools

DJB_RESTRICTED=		YES
DJB_CONFIG_PREFIX=	${PREFIX}/publicfile

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
