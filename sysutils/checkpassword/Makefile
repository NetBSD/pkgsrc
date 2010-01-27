# $NetBSD: Makefile,v 1.14 2010/01/27 18:38:15 joerg Exp $
#

DISTNAME=		checkpassword-0.90
CATEGORIES=		sysutils
MASTER_SITES=		http://cr.yp.to/checkpwd/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/checkpwd.html
COMMENT=		Simple, uniform password-checking interface to all root applications

DJB_RESTRICTED=		YES

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/checkpassword ${DESTDIR}${PREFIX}/bin

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
