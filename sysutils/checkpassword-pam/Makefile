# $NetBSD: Makefile,v 1.6 2008/06/12 02:14:46 joerg Exp $
#

DISTNAME=		checkpassword-pam-0.99
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=checkpasswd-pam/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://checkpasswd-pam.sourceforge.net/
COMMENT=		PAM checkpassword-compatible authentication program

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
