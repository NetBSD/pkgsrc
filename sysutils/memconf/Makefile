# $NetBSD: Makefile,v 1.1.1.1 2000/03/21 09:03:21 agc Exp $
#

DISTNAME=		memconf
PKGNAME=		memconf-1.23.2
CATEGORIES=		sysutils
MASTER_SITES=		http://netnow.micron.net/~tschmidt/unix/
EXTRACT_SUFX=		.gz

MAINTAINER=		agc@netbsd.org
HOMEPAGE=		http://netnow.micron.net/~tschmidt/memconf.html

ONLY_FOR_PLATFORM=	SunOS-*-* 	# only for Solaris

WRKSRC=			${WRKDIR}

EXTRACT_CMD=		${GZCAT} ${DOWNLOADED_DISTFILE} > ${WRKSRC}/memconf
NO_BUILD=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/memconf ${LOCALBASE}/sbin/memconf

.include "../../mk/bsd.pkg.mk"
