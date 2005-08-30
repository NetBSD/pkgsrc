# $NetBSD: Makefile,v 1.2 2005/08/30 12:47:52 drochner Exp $
#

DISTNAME=		nss_ldap-239
PKGREVISION=		1
CATEGORIES=		databases
MASTER_SITES=		http://www.padl.com/download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.padl.com/OSS/nss_ldap.html
COMMENT=		LDAP client for nsswitch

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+= --with-ldap-conf-file=${PKG_SYSCONFDIR}/nss_ldap.conf
CONFIGURE_ARGS+= --with-ldap-secret-file=${PKG_SYSCONFDIR}/nss_ldap.secret
CONFIGURE_ARGS+= --sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

USE_PKGINSTALL=	yes
CONF_FILES=	${EGDIR}/nss_ldap.conf ${PKG_SYSCONFDIR}/nss_ldap.conf

pre-build:
	${CP} ${FILESDIR}/netbsd.c  ${FILESDIR}/netbsd.h ${WRKSRC}
	${LN} -fs /usr/include/nsswitch.h ${BUILDLINK_DIR}/include/nss.h

.include "../../databases/openldap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
