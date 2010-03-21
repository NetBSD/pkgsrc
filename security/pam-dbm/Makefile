# $NetBSD: Makefile,v 1.10 2010/03/21 06:50:13 scottr Exp $
#

DISTNAME=		pam_dbm-0.2
PKGNAME=		pam-dbm-0.2
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.feep.net/pub/software/PAM/pam_dbm/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.feep.net/PAM/pam_dbm/
COMMENT=		PAM module for DBM authentication

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
BDB_ACCEPTED=		db1

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"

# Fix (workaround?) a bug with openpam/NetBSD
# The bug is described in PR security/39313.
#
.include "../../mk/bsd.prefs.mk"
#
.if ${OPSYS} == "NetBSD"
CFLAGS+=		-DNO_STATIC_MODULES
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/authtest ${DESTDIR}${PREFIX}/sbin/pam_dbm-authtest

.include "../../mk/bsd.pkg.mk"
