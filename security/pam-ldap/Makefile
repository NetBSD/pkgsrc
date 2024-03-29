# $NetBSD: Makefile,v 1.52 2023/10/24 22:10:55 wiz Exp $

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
