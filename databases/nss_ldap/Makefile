# $NetBSD: Makefile,v 1.30 2016/03/05 11:28:12 jperkin Exp $

DISTNAME=	nss_ldap-265
PKGREVISION=	6
CATEGORIES=	databases
MASTER_SITES=	http://www.padl.com/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.padl.com/OSS/nss_ldap.html
COMMENT=	LDAP client for nsswitch
LICENSE=	gnu-lgpl-v2

# needs nsswitch
ONLY_FOR_PLATFORM=	NetBSD-[3-9]*-* FreeBSD-*-*

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-schema-mapping
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-ldap-lib=openldap
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap-client}
CONFIGURE_ARGS+=	--with-ldap-conf-file=${PKG_SYSCONFDIR}/ldap.conf
CONFIGURE_ARGS+=	--with-ldap-secret-file=${PKG_SYSCONFDIR}/ldap.secret
CFLAGS.FreeBSD+=	-DUID_NOBODY=65534 -DGID_NOBODY=65534 # see <sys/conf.h>
CONFIGURE_ENV+=		ac_cv_header_nsswitch_h=no
MAKE_FLAGS+=		INST_UID=${BINOWN} INST_GID=${BINGRP}

# shared with security/pam-ldap
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/ldap.conf ${PKG_SYSCONFDIR}/ldap.conf

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

SUBST_CLASSES+=			fix-opsys
SUBST_STAGE.fix-opsys=		pre-configure
SUBST_MESSAGE.fix-opsys=	Fixing system name.
SUBST_FILES.fix-opsys=		Makefile.in
SUBST_SED.fix-opsys=		-e 's,@OPSYS@,${OPSYS:tl},g'

.include "../../mk/bsd.prefs.mk"

pre-build:
	${CP} ${FILESDIR}/netbsd.c  ${FILESDIR}/netbsd.h  ${FILESDIR}/freebsd.c  ${WRKSRC}
.if ${OPSYS} == "NetBSD"
	${LN} -fs /usr/include/nsswitch.h ${BUILDLINK_DIR}/include/nss.h
.endif

.include "options.mk"

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
