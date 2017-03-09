# $NetBSD: Makefile,v 1.2 2017/03/09 23:47:47 manu Exp $
#

PKGNAME=	nagios-plugin-milter-${DISTNAME:C/.*-//}
DISTNAME=	check_milter-0.2
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
