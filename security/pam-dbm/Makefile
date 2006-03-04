# $NetBSD: Makefile,v 1.6 2006/03/04 21:30:37 jlam Exp $
#

DISTNAME=		pam_dbm-0.2
PKGNAME=		pam-dbm-0.2
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.feep.net/pub/software/PAM/pam_dbm/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www-dev.cites.uiuc.edu/pam_dbm/
COMMENT=		PAM module for DBM authentication

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
BDB_ACCEPTED=		db1

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
