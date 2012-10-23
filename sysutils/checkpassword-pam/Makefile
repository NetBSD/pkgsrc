# $NetBSD: Makefile,v 1.7 2012/10/23 19:50:55 asau Exp $
#

DISTNAME=		checkpassword-pam-0.99
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=checkpasswd-pam/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://checkpasswd-pam.sourceforge.net/
COMMENT=		PAM checkpassword-compatible authentication program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
