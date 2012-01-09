# $NetBSD: Makefile,v 1.24 2012/01/09 05:16:29 manu Exp $

DISTNAME=	nss_ldap-265
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://www.padl.com/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.padl.com/OSS/nss_ldap.html
COMMENT=	LDAP client for nsswitch
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

# needs nsswitch
ONLY_FOR_PLATFORM=	NetBSD-[3-9]*-*

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-schema-mapping
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-ldap-lib=openldap
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap-client}
CONFIGURE_ARGS+=	--with-ldap-conf-file=${PKG_SYSCONFDIR}/ldap.conf
CONFIGURE_ARGS+=	--with-ldap-secret-file=${PKG_SYSCONFDIR}/ldap.secret
MAKE_FLAGS+=		INST_UID=${BINOWN} INST_GID=${BINGRP}

# shared with security/pam-ldap
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/ldap.conf ${PKG_SYSCONFDIR}/ldap.conf

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

pre-build:
	${CP} ${FILESDIR}/netbsd.c  ${FILESDIR}/netbsd.h ${WRKSRC}
	${LN} -fs /usr/include/nsswitch.h ${BUILDLINK_DIR}/include/nss.h

.include "options.mk"

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
