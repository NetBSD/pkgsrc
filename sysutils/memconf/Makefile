# $NetBSD: Makefile,v 1.6 2003/07/17 22:53:42 grant Exp $
#

DISTNAME=		memconf
PKGNAME=		memconf-1.23.2
WRKSRC=			${WRKDIR}
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/packages/distfiles/
EXTRACT_SUFX=		.gz

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://netnow.micron.net/~tschmidt/memconf.html
COMMENT=		physical memory information utility

ONLY_FOR_PLATFORM=	SunOS-*-* 	# only for Solaris

NO_BUILD=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/memconf ${LOCALBASE}/sbin/memconf

.include "../../mk/bsd.pkg.mk"
