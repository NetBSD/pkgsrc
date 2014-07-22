# $NetBSD: Makefile,v 1.1 2014/07/22 12:52:53 manu Exp $
#

PKGNAME=	nagios-plugin-syncrepl-${DISTNAME:C/.*-//}
DISTNAME=	check_syncrepl-0.1
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/nagios-local/
COMMENT=	LDAP replication monitoring plugin for Nagios
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+= libexec/nagios

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_syncrepl \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
