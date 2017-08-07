# $NetBSD: Makefile,v 1.2 2017/08/07 09:30:45 jlam Exp $
#

PKGNAME=	nagios-plugin-gfbricks-${DISTNAME:C/.*-//}
PKGREVISION=	1
DISTNAME=	check_gfbricks-0.2
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/nagios-local/
COMMENT=	GlusterFS bricks monitoring plugin for Nagios
LICENSE=	modified-bsd

INSTALLATION_DIRS+= libexec/nagios

BUILD_DEFS+=		NAGIOS_GROUP
PKG_GROUPS_VARS=	NAGIOS_GROUP
PKG_GROUPS=		${NAGIOS_GROUP}

SPECIAL_PERMS+= ${PREFIX}/libexec/nagios/check_gfbricks \
		${REAL_ROOT_USER} ${NAGIOS_GROUP} 4554

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_gfbricks \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
