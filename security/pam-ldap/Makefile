# $NetBSD: Makefile,v 1.53 2025/11/03 19:17:53 tron Exp $

DISTNAME=	pam_ldap-186
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	8
CATEGORIES=	security
#MASTER_SITES+=	http://www.padl.com/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.padl.com/pam_ldap.html
COMMENT=	Pluggable authentication module for LDAP directories
LICENSE=	gnu-lgpl-v2

ONLY_FOR_PLATFORM=	NetBSD-*-* FreeBSD-*-* SunOS-*-*

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-ldap-lib=openldap
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap-client}
CONFIGURE_ARGS+=	--with-ldap-conf-file=${PKG_SYSCONFDIR}/ldap.conf
CONFIGURE_ARGS+=	--with-ldap-secret-file=${PKG_SYSCONFDIR}/ldap.secret

# Stop "configure" from finding the badly hidden gethostbyname_r()
# under NetBSD which breaks the build.
CONFIGURE_ENV.NetBSD+=	ac_cv_func_gethostbyname_r=no

# shared with databases/nss_ldap
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/ldap.conf ${PKG_SYSCONFDIR}/ldap.conf

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}
INSTALL_TARGET=		install install-data

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"

post-install:
.for file in ldapns.schema ns-pwd-policy.schema
	cd ${WRKSRC} && ${INSTALL_DATA} ${file} ${DESTDIR}${EGDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
