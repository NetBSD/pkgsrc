# $NetBSD: Makefile,v 1.1.1.1 2004/08/12 09:22:00 schmonz Exp $
#

DISTNAME=		checkpassword-pam-0.98
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=checkpasswd-pam/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://checkpasswd-pam.sourceforge.net/
COMMENT=		PAM checkpassword-compatible authentication program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin man/man8

.include "../../security/PAM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
