# $NetBSD: Makefile,v 1.6 2002/07/13 21:35:15 wiz Exp $
#

DISTNAME=	pam_ldap-150
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.padl.com/pub/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.padl.com/pam_ldap.html
COMMENT=	pluggable authentication module for LDAP directories

DEPENDS+=	openldap-[0-9]*:../../databases/openldap
DEPENDS+=	PAM-[0-9]*:../../security/PAM

GNU_CONFIGURE=	YES
#CPPFLAGS+=	-I${WRKSRC}
CONFIGURE_ARGS+=	--with-ldap-lib=openldap
CONFIGURE_ARGS+=	--with-ldap-dir=${PREFIX}
CONFIGURE_ARGS+=	--with-ldap-conf-file=${PREFIX}/etc/pam/pam.conf
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/pam
INSTALL_TARGET=	install install-data

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pam-ldap
.for doc in COPYING COPYING.LIB INSTALL ChangeLog
	cd ${WRKSRC} && ${INSTALL_DATA} ${doc} ${PREFIX}/share/doc/pam-ldap
.endfor

.include "../../mk/bsd.pkg.mk"
