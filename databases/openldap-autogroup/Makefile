# $NetBSD: Makefile,v 1.2 2023/10/24 22:08:30 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-autogroup-/}
PKGREVISION=	1
COMMENT=	Hide specific attributes unless explicitely requested for OpenLDAP

CONFLICTS+=	openldap<2.3.23nb1
DEPENDS+=	openldap-server>=2.4.13nb1:../../databases/openldap-server

USE_LIBTOOL=		yes

BUILD_DIRS+=		include libraries contrib/slapd-modules/autogroup
INSTALLATION_DIRS=	lib/openldap ${PKGMANDIR}/man5

do-install:
	${INSTALL_MAN}							    \
		${WRKSRC}/contrib/slapd-modules/autogroup/slapo-autogroup.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${LIBTOOL} --mode=install ${INSTALL_DATA}			    \
		   ${WRKSRC}/contrib/slapd-modules/autogroup/autogroup.la   \
		   ${DESTDIR}${PREFIX}/lib/openldap

.include "../../databases/openldap/Makefile.common"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../databases/openldap-server/options.mk"
.include "../../mk/bsd.pkg.mk"
