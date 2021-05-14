# $NetBSD: Makefile,v 1.7 2021/05/14 13:05:45 nia Exp $
#

PKGNAME=	nagios-plugin-syncrepl-${DISTNAME:C/.*-//}
DISTNAME=	check_syncrepl-0.5
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/nagios-local/
COMMENT=	LDAP replication monitoring plugin for Nagios
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	libexec/nagios

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_syncrepl \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
