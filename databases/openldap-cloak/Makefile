# $NetBSD: Makefile,v 1.22 2024/01/31 18:17:21 adam Exp $

PKGNAME=	${DISTNAME:S/-/-cloak-/}
COMMENT=	Hide specific attributes unless explicitely requested for OpenLDAP

CONFLICTS+=	openldap<2.3.23nb1
DEPENDS+=	openldap-server>=2.4.13nb1:../../databases/openldap-server

BUILD_DIRS=		include contrib/slapd-modules/cloak
INSTALLATION_DIRS=	lib/openldap ${PKGMANDIR}/man5

do-install:
	${INSTALL_MAN} ${WRKSRC}/contrib/slapd-modules/cloak/slapo-cloak.5\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${LIBTOOL} --mode=install ${INSTALL_DATA}			\
		   ${WRKSRC}/contrib/slapd-modules/cloak/cloak.la	\
		   ${DESTDIR}${PREFIX}/lib/openldap

.include "../../databases/openldap/Makefile.common"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../databases/openldap-server/options.mk"
.include "../../mk/bsd.pkg.mk"
