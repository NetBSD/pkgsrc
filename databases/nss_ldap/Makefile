# $NetBSD: Makefile,v 1.37 2023/10/24 22:08:30 wiz Exp $

DISTNAME=	nss_ldap-266a
#PKGREVISION=	1
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=manu0401/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.padl.com/OSS/nss_ldap.html
COMMENT=	LDAP client for nsswitch
LICENSE=	gnu-lgpl-v2

# needs nsswitch
ONLY_FOR_PLATFORM=	NetBSD-*-* FreeBSD-*-* Linux-*-*

USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-schema-mapping
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-ldap-lib=openldap
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap-client}
CONFIGURE_ARGS+=	--with-ldap-conf-file=${PKG_SYSCONFDIR}/ldap.conf
CONFIGURE_ARGS+=	--with-ldap-secret-file=${PKG_SYSCONFDIR}/ldap.secret
CFLAGS.FreeBSD+=	-DUID_NOBODY=65534 -DGID_NOBODY=65534 # see <sys/conf.h>
MAKE_FLAGS+=		INST_UID=${BINOWN} INST_GID=${BINGRP}

REPLACE_PERL+=		vers_string

INSTALLATION_DIRS+=	share/examples/nss_ldap

# shared with security/pam-ldap
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/ldap.conf ${PKG_SYSCONFDIR}/ldap.conf
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/ldap.conf ${DESTDIR}${EGDIR}/ldap.conf

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
