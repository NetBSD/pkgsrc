# $NetBSD: Makefile,v 1.8 2004/01/20 12:26:15 agc Exp $
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

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/memconf ${LOCALBASE}/sbin/memconf

.include "../../mk/bsd.pkg.mk"
