# $NetBSD: Makefile,v 1.6 2020/01/26 17:31:51 rillig Exp $
#

PKGNAME=	nagios-plugin-fstab-${DISTNAME:C/.*-//}
DISTNAME=	check_fstab-0.3
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/nagios-local/
COMMENT=	Mount points and swaps monitoring plugin for Nagios
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-*-* OpenBSD-*-* DragonFly-*-*

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	libexec/nagios

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_fstab \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
