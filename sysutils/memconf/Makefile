# $NetBSD: Makefile,v 1.5 2003/03/29 12:42:28 jmmv Exp $
#

DISTNAME=		memconf
PKGNAME=		memconf-1.23.2
WRKSRC=			${WRKDIR}
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/
EXTRACT_SUFX=		.gz

MAINTAINER=		agc@netbsd.org
HOMEPAGE=		http://netnow.micron.net/~tschmidt/memconf.html
COMMENT=		physical memory information utility

ONLY_FOR_PLATFORM=	SunOS-*-* 	# only for Solaris

NO_BUILD=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/memconf ${LOCALBASE}/sbin/memconf

.include "../../mk/bsd.pkg.mk"
