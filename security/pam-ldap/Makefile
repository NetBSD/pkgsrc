# $NetBSD: Makefile,v 1.8 2003/05/02 14:15:35 wiz Exp $
#

DISTNAME=	pam_ldap-150
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.padl.com/pub/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.padl.com/pam_ldap.html
COMMENT=	pluggable authentication module for LDAP directories

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
CONFIGURE_ARGS+=	--with-ldap-lib=openldap
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap}
CONFIGURE_ARGS+=	--with-ldap-conf-file=${BUILDLINK_PREFIX.pam}/etc/pam/pam.conf
CONFIGURE_ARGS+=	--sysconfdir=${BUILDLINK_PREFIX.pam}/etc/pam
INSTALL_TARGET=	install install-data

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pam-ldap
.for doc in COPYING COPYING.LIB INSTALL ChangeLog
	cd ${WRKSRC} && ${INSTALL_DATA} ${doc} ${PREFIX}/share/doc/pam-ldap
.endfor

.include "../../databases/openldap/buildlink2.mk"
.include "../../security/PAM/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
