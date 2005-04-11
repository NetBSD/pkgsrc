# $NetBSD: Makefile,v 1.4 2005/04/11 21:47:23 tv Exp $
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

INSTALLATION_DIRS=	bin man/man8

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
