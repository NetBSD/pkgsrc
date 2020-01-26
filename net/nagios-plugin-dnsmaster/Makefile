# $NetBSD: Makefile,v 1.3 2020/01/26 17:31:51 rillig Exp $
#

DISTNAME=	check_dnsmaster-0.1
PKGNAME=	nagios-plugin-dnsmaster-${DISTNAME:C/.*-//}
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/nagios-local/
COMMENT=	Domain NS record monitoring plugin for Nagios
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	libexec/nagios

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_dnsmaster \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
