# $NetBSD: Makefile,v 1.29 2023/10/24 22:08:31 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-smbk5pwd-/}
PKGREVISION=	1
COMMENT=	Samba and Kerberos password sync for OpenLDAP

CONFLICTS+=	openldap<2.3.23nb1
DEPENDS+=	openldap-server>=2.4.13nb1:../../databases/openldap-server

BUILD_DIRS=		include contrib/slapd-modules/smbk5pwd
INSTALLATION_DIRS+=	lib/openldap

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB}			\
		   ${WRKSRC}/contrib/slapd-modules/smbk5pwd/smbk5pwd.la	\
		   ${DESTDIR}${PREFIX}/lib/openldap

.include "../../mk/bsd.prefs.mk"

.include "../../databases/openldap-server/options.mk"

.include "../../mk/krb5.buildlink3.mk"
.if ${KRB5_TYPE} == "heimdal"
CPPFLAGS+=	-DDO_KRB5
LIBS+=		-lkrb5 -lkadm5srv
.endif

LIBS+=		-L${BUILDLINK_PREFIX.openssl}/lib
MAKE_ENV+=	EXTRA_LIBS=${LIBS:M*:Q}

.include "../../databases/openldap/Makefile.common"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
