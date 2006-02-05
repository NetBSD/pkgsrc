# $NetBSD: Makefile,v 1.8 2006/02/05 23:08:32 joerg Exp $
#

DISTNAME=		nss_ldap-240
PKGREVISION=		2
CATEGORIES=		databases
MASTER_SITES=		http://www.padl.com/download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.padl.com/OSS/nss_ldap.html
COMMENT=		LDAP client for nsswitch

# needs nsswitch
ONLY_FOR_PLATFORM=	NetBSD-3.*-*

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+= --with-ldap-conf-file=${PKG_SYSCONFDIR}/nss_ldap.conf
CONFIGURE_ARGS+= --with-ldap-secret-file=${PKG_SYSCONFDIR}/nss_ldap.secret
CONFIGURE_ARGS+= --sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

CONF_FILES=	${EGDIR}/nss_ldap.conf ${PKG_SYSCONFDIR}/nss_ldap.conf

pre-build:
	${CP} ${FILESDIR}/netbsd.c  ${FILESDIR}/netbsd.h ${WRKSRC}
	${LN} -fs /usr/include/nsswitch.h ${BUILDLINK_DIR}/include/nss.h

.include "../../databases/openldap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
