# $NetBSD: Makefile,v 1.7 2003/07/21 17:24:20 martti Exp $
#

DISTNAME=		memconf
PKGNAME=		memconf-1.23.2
WRKSRC=			${WRKDIR}
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/packages/distfiles/
EXTRACT_SUFX=		.gz

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://netnow.micron.net/~tschmidt/memconf.html
COMMENT=		Physical memory information utility

ONLY_FOR_PLATFORM=	SunOS-*-* 	# only for Solaris

NO_BUILD=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/memconf ${LOCALBASE}/sbin/memconf

.include "../../mk/bsd.pkg.mk"
