# $NetBSD: Makefile,v 1.15 2004/10/03 00:18:12 tv Exp $
#

DISTNAME=	pam_ldap-150
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.padl.com/pub/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.padl.com/pam_ldap.html
COMMENT=	Pluggable authentication module for LDAP directories

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
CONFIGURE_ARGS+=	--with-ldap-lib=openldap
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap}
CONFIGURE_ARGS+=	--with-ldap-conf-file=${BUILDLINK_PREFIX.pam}/etc/pam/ldap.conf
CONFIGURE_ARGS+=	--sysconfdir=${BUILDLINK_PREFIX.pam}/etc/pam
INSTALL_TARGET=	install install-data

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pam-ldap
.for doc in COPYING COPYING.LIB INSTALL ChangeLog
	cd ${WRKSRC} && ${INSTALL_DATA} ${doc} ${PREFIX}/share/doc/pam-ldap
.endfor

.include "../../databases/openldap/buildlink3.mk"
.include "../../security/PAM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
