# $NetBSD: Makefile,v 1.3 2004/11/15 17:54:50 jlam Exp $
#

DISTNAME=		pam_dbm-0.2
PKGNAME=		pam-dbm-0.2
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.feep.net/pub/software/PAM/pam_dbm/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www-dev.cites.uiuc.edu/pam_dbm/
COMMENT=		PAM module for DBM authentication

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
BDB_ACCEPTED=		db1

.include "../../security/PAM/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
