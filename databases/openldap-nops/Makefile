# $NetBSD: Makefile,v 1.22 2020/02/10 15:13:06 adam Exp $

PKGNAME=	${DISTNAME:S/-/-nops-/}
COMMENT=	Remove null-ops for OpenLDAP

CONFLICTS+=	openldap<2.3.23nb1
DEPENDS+=	openldap-server>=2.4.13nb1:../../databases/openldap-server

USE_LIBTOOL=		yes

BUILD_DIRS=		include contrib/slapd-modules/nops
INSTALLATION_DIRS=	lib/openldap ${PKGMANDIR}/man5

do-install:
	${INSTALL_MAN} ${WRKSRC}/contrib/slapd-modules/nops/slapo-nops.5\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${LIBTOOL} --mode=install ${INSTALL_DATA}			\
		   ${WRKSRC}/contrib/slapd-modules/nops/nops.la		\
		   ${DESTDIR}${PREFIX}/lib/openldap

.include "../../databases/openldap/Makefile.common"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../databases/openldap-server/options.mk"
.include "../../mk/bsd.pkg.mk"
