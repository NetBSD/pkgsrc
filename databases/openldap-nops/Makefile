# $NetBSD: Makefile,v 1.8 2010/02/19 20:49:29 ghen Exp $

PKGNAME=		${DISTNAME:S/-/-nops-/}
COMMENT=		Remove null-ops for OpenLDAP

CONFLICTS+=		openldap<2.3.23nb1

DEPENDS+=		openldap-server>=2.4.13nb1:../../databases/openldap-server

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes

BUILD_DIRS=		include contrib/slapd-modules/nops

INSTALLATION_DIRS=	lib/openldap ${PKGMANDIR}/man5

do-install:
	${INSTALL_MAN} ${WRKSRC}/contrib/slapd-modules/nops/slapo-nops.5\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${LIBTOOL} --mode=install 					\
		   ${INSTALL_DATA}					\
		   ${WRKSRC}/contrib/slapd-modules/nops/nops.la		\
		   ${DESTDIR}${PREFIX}/lib/openldap

.include "../../databases/openldap/Makefile.common"

.include "../../databases/db4/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
