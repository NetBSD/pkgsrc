# $NetBSD: Makefile,v 1.3 2001/05/08 16:15:56 agc Exp $
#

DISTNAME=		memconf
PKGNAME=		memconf-1.23.2
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/
EXTRACT_SUFX=		.gz

MAINTAINER=		agc@netbsd.org
HOMEPAGE=		http://netnow.micron.net/~tschmidt/memconf.html
COMMENT=		physical memory information utility

ONLY_FOR_PLATFORM=	SunOS-*-* 	# only for Solaris

WRKSRC=			${WRKDIR}

EXTRACT_CMD=		${GZCAT} ${DOWNLOADED_DISTFILE} > ${WRKSRC}/memconf
NO_BUILD=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/memconf ${LOCALBASE}/sbin/memconf

.include "../../mk/bsd.pkg.mk"
