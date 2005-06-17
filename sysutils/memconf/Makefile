# $NetBSD: Makefile,v 1.9 2005/06/17 03:50:34 jlam Exp $
#

DISTNAME=		memconf
PKGNAME=		memconf-1.23.2
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/packages/distfiles/
EXTRACT_SUFX=		.gz

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://netnow.micron.net/~tschmidt/memconf.html
COMMENT=		Physical memory information utility

ONLY_FOR_PLATFORM=	SunOS-*-* 	# only for Solaris

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/memconf ${LOCALBASE}/sbin/memconf

.include "../../mk/bsd.pkg.mk"
