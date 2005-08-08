# $NetBSD: Makefile,v 1.1.1.1 2005/08/08 09:47:42 drochner Exp $
#

DISTNAME=		nss_ldap-239
CATEGORIES=		databases
MASTER_SITES=		http://www.padl.com/download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.padl.com/OSS/nss_ldap.html
COMMENT=		LDAP client for nsswitch

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--with-ldap-conf-file=/etc/nss_ldap.conf
CONFIGURE_ARGS+=	--with-ldap-secret-file=/etc/nss_ldap.secret

pre-build:
	${CP} ${FILESDIR}/netbsd.c  ${FILESDIR}/netbsd.h ${WRKSRC}
	${LN} -s /usr/include/nsswitch.h ${BUILDLINK_DIR}/include/nss.h

.include "../../databases/openldap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
