# $NetBSD: Makefile,v 1.6 2010/02/19 20:49:29 ghen Exp $

PKGNAME=		${DISTNAME:S/-/-smbk5pwd-/}
COMMENT=		Samba and Kerberos password sync for OpenLDAP

CONFLICTS+=		openldap<2.3.23nb1

DEPENDS+=		openldap-server>=2.4.13nb1:../../databases/openldap-server

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes

BUILD_DIRS=		include contrib/slapd-modules/smbk5pwd

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib/openldap
	${LIBTOOL} --mode=install 					\
		   ${INSTALL_DATA}					\
		   ${WRKSRC}/contrib/slapd-modules/smbk5pwd/smbk5pwd.la	\
		   ${DESTDIR}${PREFIX}/lib/openldap

.include "../../databases/openldap/Makefile.common"

.include "../../databases/db4/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
