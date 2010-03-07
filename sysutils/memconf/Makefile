# $NetBSD: Makefile,v 1.12 2010/03/07 23:15:11 joerg Exp $
#

DISTNAME=		memconf
PKGNAME=		memconf-1.23.2
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/packages/distfiles/
EXTRACT_SUFX=		.gz

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://netnow.micron.net/~tschmidt/memconf.html
COMMENT=		Physical memory information utility

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	SunOS-*-* 	# only for Solaris

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/memconf ${DESTDIR}${PREFIX}/sbin/memconf

.include "../../mk/bsd.pkg.mk"
