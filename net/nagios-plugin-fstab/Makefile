# $NetBSD: Makefile,v 1.3 2015/07/12 06:43:24 dholland Exp $
#

PKGNAME=	nagios-plugin-fstab-${DISTNAME:C/.*-//}
DISTNAME=	check_fstab-0.2
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/nagios-local/
COMMENT=	Mount points and swaps monitoring plugin for Nagios
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-*-* OpenBSD-*-* DragonFly-*-* \
			MirBSD-*-* Bitrig-*-* Linux-*-*

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+= libexec/nagios

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_fstab \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
