# $NetBSD: Makefile,v 1.1 2015/09/25 13:20:36 manu Exp $
#

PKGNAME=	nagios-plugin-gfbricks-${DISTNAME:C/.*-//}
DISTNAME=	check_gfbricks-0.2
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/nagios-local/
COMMENT=	GlusterFS bricks monitoring plugin for Nagios
LICENSE=	modified-bsd

INSTALLATION_DIRS+= libexec/nagios

SPECIAL_PERMS+= ${PREFIX}/libexec/nagios/check_gfbricks \
		${REAL_ROOT_USER} ${NAGIOS_GROUP} 4554
BUILD_DEFS+=	${NAGIOS_GROUP}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_gfbricks \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
