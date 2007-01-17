# $NetBSD: Makefile,v 1.26.6.1 2007/01/17 17:10:31 salo Exp $
#

DISTNAME=	pam_ldap-183
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.padl.com/pub/
MASTER_SITES+=	http://www.padl.com/download/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.padl.com/pam_ldap.html
COMMENT=	Pluggable authentication module for LDAP directories

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ldap-lib=openldap
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap-client}
CONFIGURE_ARGS+=	--with-ldap-conf-file=${PKG_SYSCONFDIR}/pam_ldap.conf
CONFIGURE_ARGS+=	--with-ldap-secret-file=${PKG_SYSCONFDIR}/pam_ldap.secret
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

MAKE_ENV+=		SHLIBTOOL=${SHLIBTOOL:Q}

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}
INSTALL_TARGET=		install install-data

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=	${EGDIR}/pam_ldap.conf ${PKG_SYSCONFDIR}/pam_ldap.conf

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
.for file in COPYING COPYING.LIB
	cd ${WRKSRC} && ${INSTALL_DATA} ${file} ${DOCDIR}
.endfor
.for file in ldapns.schema ns-pwd-policy.schema
	cd ${WRKSRC} && ${INSTALL_DATA} ${file} ${EGDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
