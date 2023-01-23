# $NetBSD: Makefile,v 1.1 2023/01/23 15:29:37 manu Exp $
#

DISTNAME=	check_ipf-0.2
PKGNAME=	nagios-plugin-ipf-${DISTNAME:C/.*-//}
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/nagios-local/
COMMENT=	IP filter states monitoring plugin for Nagios
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-*-* OpenBSD-*-* DragonFly-*-*

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	libexec/nagios

SPECIAL_PERMS+= ${PREFIX}/libexec/nagios/check_ipf \
		${REAL_ROOT_USER} ${NAGIOS_GROUP} 4554

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_ipf \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
