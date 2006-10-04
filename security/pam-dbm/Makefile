# $NetBSD: Makefile,v 1.8 2006/10/04 21:58:14 wiz Exp $
#

DISTNAME=		pam_dbm-0.2
PKGNAME=		pam-dbm-0.2
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.feep.net/pub/software/PAM/pam_dbm/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.feep.net/PAM/pam_dbm/
COMMENT=		PAM module for DBM authentication

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
BDB_ACCEPTED=		db1

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/authtest ${PREFIX}/sbin/pam_dbm-authtest

.include "../../mk/bsd.pkg.mk"
