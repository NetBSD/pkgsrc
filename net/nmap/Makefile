# $NetBSD: Makefile,v 1.7 2000/01/28 14:36:37 agc Exp $
#

DISTNAME=	nmap-2.12
CATEGORIES=	net
MASTER_SITES=	http://www.insecure.org/nmap/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.insecure.org/nmap/index.html

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	INSTALL=${INSTALL}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	CPPFLAGS=""
.endif

.include "../../mk/bsd.pkg.mk"
