# $NetBSD: Makefile,v 1.1 2013/10/01 03:37:15 manu Exp $
#

PKGNAME=	nagios-plugin-milter-${DISTNAME:C/.*-//}
DISTNAME=	check_milter-0.1
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/nagios-local/
COMMENT=	Milter monitoring plugin for Nagios
LICENSE=	modified-bsd

INSTALLATION_DIRS+= libexec/nagios

SMMSP_USER?=	smmsp
SPECIAL_PERMS+= ${PREFIX}/libexec/nagios/check_milter \
		${SMMSP_USER} ${NAGIOS_GROUP} 4554
BUILD_DEFS+=    ${NAGIOS_GROUP}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_milter \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
