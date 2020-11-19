# $NetBSD: Makefile,v 1.19 2020/11/19 08:11:18 schmonz Exp $
#

DISTNAME=		publicfile-0.52
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://cr.yp.to/publicfile/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://cr.yp.to/publicfile.html
COMMENT=		Secure read-only HTTP and FTP servers
LICENSE=		djb-nonlicense

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools

DJB_CONFIG_PREFIX=	${PREFIX}/publicfile

SUBST_CLASSES+=		djberrno

.include "options.mk"

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
