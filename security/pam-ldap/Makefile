# $NetBSD: Makefile,v 1.33 2010/10/28 08:06:19 adam Exp $

DISTNAME=	pam_ldap-185
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.padl.com/pub/ \
		http://www.padl.com/download/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.padl.com/pam_ldap.html
COMMENT=	Pluggable authentication module for LDAP directories
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ldap-lib=openldap
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap-client}
CONFIGURE_ARGS+=	--with-ldap-conf-file=${PKG_SYSCONFDIR}/pam_ldap.conf
CONFIGURE_ARGS+=	--with-ldap-secret-file=${PKG_SYSCONFDIR}/pam_ldap.secret
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

# Fix (workaround?) a bug with openpam/NetBSD
# The bug is described in PR security/39313.
#
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CFLAGS+=		-DNO_STATIC_MODULES
.endif

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}
INSTALL_TARGET=		install install-data

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

INSTALLATION_DIRS=	${DOCDIR}

CONF_FILES=	${EGDIR}/pam_ldap.conf ${PKG_SYSCONFDIR}/pam_ldap.conf

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"

post-install:
.for file in COPYING COPYING.LIB
	cd ${WRKSRC} && ${INSTALL_DATA} ${file} ${DESTDIR}${DOCDIR}
.endfor
.for file in ldapns.schema ns-pwd-policy.schema
	cd ${WRKSRC} && ${INSTALL_DATA} ${file} ${DESTDIR}${EGDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
